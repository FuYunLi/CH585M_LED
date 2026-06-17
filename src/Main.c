/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/11/20
 * Description        : LED例子 - SINGLE模式测试（验证LEDC基本功能）
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH58x_common.h"
#include "ch58x_drv_ledc.h"

/* 测试数据：与官方例程一致 */
__attribute__((__aligned__(4))) uint32_t tx_data[8] = { 0x01020408, 0x10204080, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

/* 位序和极性配置 */
#define LSB_HSB 0 // LED串行数据位序, 1:高位在前;  0:低位在前
#define POLAR   0 // LED数据输出极性, 0:直通; 1:反相

/* 中断计数器 */
volatile uint32_t irq_count = 0;

/* HUB75 控制引脚定义 */
#define PIN_LAT GPIO_Pin_7
#define PIN_OE  GPIO_Pin_8
#define PIN_A   GPIO_Pin_9
#define PIN_B   GPIO_Pin_10
#define PIN_C   GPIO_Pin_11
#define PIN_D   GPIO_Pin_12
#define PIN_E   GPIO_Pin_13
#define PIN_CLK GPIO_Pin_4

#define LAT_HIGH() GPIOB_SetBits(PIN_LAT)
#define LAT_LOW()  GPIOB_ResetBits(PIN_LAT)
#define OE_HIGH()  GPIOB_SetBits(PIN_OE)
#define OE_LOW()   GPIOB_ResetBits(PIN_OE)

/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   调试初始化 (适配用户硬件: PB4=RX, PB7=TX)
 *
 * @return  none
 */
void DebugInit(void)
{
    GPIOB_SetBits(GPIO_Pin_7);
    GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_PU);
    GPIOB_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);
    UART0_DefInit();
}

/**
 * @brief ICN2038S 驱动 IC 寄存器初始化
 *
 * 必须在显示前调用，写入 REG1=0x7FFF (1/32扫描模式)
 */
static void icn2038s_init(void)
{
    uint16_t reg1 = 0x7FFF;

    /* 步骤1: 清空移位寄存器（发全0行×3次） */
    for (uint8_t flush = 0; flush < 3; flush++)
    {
        LAT_LOW();
        for (uint8_t i = 0; i < 64; i++)
        {
            GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
            GPIOA_SetBits(PIN_CLK);
            __nop();
            __nop();
            __nop();
            __nop();
            GPIOA_ResetBits(PIN_CLK);
        }
        LAT_HIGH();
        LAT_LOW();
    }

    /* 步骤2: 写 REG1，移入 64 bits REG1 数据 (4颗级联 IC × 16bit = 64bit) */
    LAT_LOW();
    GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);

    for (uint8_t ic = 0; ic < 4; ic++)
    {
        for (int8_t bit = 15; bit >= 0; bit--)
        {
            uint8_t val = (reg1 >> bit) & 1;
            if (val)
                GPIOA_SetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
            else
                GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
            GPIOA_SetBits(PIN_CLK);
            __nop();
            __nop();
            __nop();
            __nop();
            GPIOA_ResetBits(PIN_CLK);
        }
    }

    /* 步骤3: LAT HIGH + 11 CLK = 写入 REG1 */
    GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
    LAT_HIGH();
    for (uint8_t i = 0; i < 11; i++)
    {
        GPIOA_SetBits(PIN_CLK);
        __nop();
        __nop();
        __nop();
        __nop();
        GPIOA_ResetBits(PIN_CLK);
    }
    LAT_LOW();

    /* 步骤4: 再次 flush 确保移位寄存器清零 */
    for (uint8_t flush = 0; flush < 5; flush++)
    {
        LAT_LOW();
        for (uint8_t i = 0; i < 64; i++)
        {
            GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
            GPIOA_SetBits(PIN_CLK);
            __nop();
            __nop();
            GPIOA_ResetBits(PIN_CLK);
        }
        LAT_HIGH();
        LAT_LOW();
    }

    PRINT("ICN2038S Init Done (REG1=0x7FFF)\n");
}

/**
 * @brief 手动 LAT 锁存 + 3 CLK (ICN2038S 数据锁存命令)
 */
static void lat_latch(void)
{
    LAT_HIGH();
    for (uint8_t i = 0; i < 3; i++)
    {
        GPIOA_SetBits(PIN_CLK);
        __nop();
        __nop();
        GPIOA_ResetBits(PIN_CLK);
    }
    LAT_LOW();
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数 - SINGLE模式测试
 *
 * @return  none
 */
int main()
{
    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(SYSCLK_FREQ);

    DebugInit();
    PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);
    PRINT("=== SINGLE Mode Test (With ICN2038S Init) ===\n");

    /* LED CLK */
    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);

    /* LED Data: PA0~PA8 */
    GPIOA_ModeCfg(GPIO_Pin_0, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_1, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_3, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_5, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_6, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeOut_PP_5mA);

    /* HUB75 控制引脚初始化 */
    OE_HIGH(); // OE = HIGH (关闭显示)
    LAT_LOW(); // LAT = LOW
    GPIOB_ModeCfg(PIN_LAT, GPIO_ModeOut_PP_5mA);
    GPIOB_ModeCfg(PIN_OE, GPIO_ModeOut_PP_5mA);

    /* 行地址: 选择第0行 */
    GPIOA_ResetBits(PIN_A | PIN_B | PIN_C | PIN_D | PIN_E);
    GPIOA_ModeCfg(PIN_A, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(PIN_B, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(PIN_C, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(PIN_D, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(PIN_E, GPIO_ModeOut_PP_5mA);

    /* 等待驱动 IC 上电稳定 */
    DelayMs(200);

    /* 关键：初始化 ICN2038S 驱动 IC */
    icn2038s_init();

    /* 配置分频和模式选择 - SINGLE模式, DIV=128 */
    ch58x_led_controller_init(CH58X_LED_OUT_MODE_SINGLE, 128);
    PRINT("LEDC Init: SINGLE mode, DIV=128\n");

    /* 打印初始状态 */
    PRINT("R8_LED_CTRL_MOD  = 0x%02X\n", R8_LED_CTRL_MOD);
    PRINT("R16_LED_STATUS   = 0x%04X\n", R16_LED_STATUS);

    /* 开始发送 */
    TMR_DMACfg(ENABLE, (uint16_t)(uint32_t)&tx_data, 2, Mode_Single);
    PRINT("DMA started\n");

    /* 使能输出 */
    LED_ENABLE();
    PRINT("LED output enabled\n");

    /* 使能中断 */
    PFIC_EnableIRQ(LED_IRQn);
    PRINT("LED IRQ enabled\n");

    /* OE 极性探测 */
    PRINT("\n=== OE Polarity Test ===\n");
    PRINT("Watch screen: R1 channel should flicker RED\n\n");

    uint32_t last_count = 0;
    while (1)
    {
        OE_LOW(); // OE = LOW (显示使能)
        DelayMs(500);
        OE_HIGH(); // OE = HIGH (关闭显示)
        DelayMs(500);

        PRINT("STATUS=0x%04X IRQ=%d (delta=%d)\n", R16_LED_STATUS, irq_count, irq_count - last_count);
        last_count = irq_count;
    }
}

/*********************************************************************
 * @fn      LED_IRQHandler
 *
 * @brief   LED中断函数 - 添加正确的 LAT 锁存
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void LED_IRQHandler(void)
{
    if (LED_GetITFlag(RB_LED_IF_DMA_END))
    {
        LED_ClearITFlag(RB_LED_IF_DMA_END);
        irq_count++;

        /* 关键：DMA 完成后执行 LAT 锁存 + 3 CLK */
        lat_latch();

        /* 继续发送下一帧 */
        ch58x_led_controller_send(tx_data, 2);
    }
}
