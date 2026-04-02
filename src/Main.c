/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/11/20
 * Description        : LED例子
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH58x_common.h"
#include "ch58x_drv_ledc.h"

// 每个 uint32_t = 1 个像素（6通道 × 4bit 灰度，高8位未用）
// bit[3:0]   = R1 亮度 (0-15)
// bit[7:4]   = G1 亮度
// bit[11:8]  = B1 亮度
// bit[15:12] = R2 亮度
// bit[19:16] = G2 亮度
// bit[23:20] = B2 亮度
#define HUB75_COLS 64

__attribute__((__aligned__(4))) uint32_t row_data[HUB75_COLS]; // 64像素，1 uint32_t/像素

void Fill_Test_Data(void)
{
    // 全通道全亮（白色），确认行数和 OE 极性
    for (int i = 0; i < HUB75_COLS; i++)
        row_data[i] = 0xFFFFFFFF;
}



/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   调试初始化
 *
 * @return  none
 */
void DebugInit(void)
{
    GPIOB_SetBits(GPIO_Pin_7);
    GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOB_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
    UART0_DefInit();
}

/* LED控制配置 */
#define LED_MODE    CH58X_LED_OUT_MODE_EIGHT
#define LED_CLK_DIV 4
// HUB75E 协议要求 MSB 优先（高位先出），禁止开启 LSB_HSB。
// ch58x_led_controller_init 已不再强制写位序，复位值即 MSB 优先。
#define LSB_HSB 0   // 0=MSB first (HUB75 协议要求，勿改)
#define POLAR   0   // LED数据输出极性, 0:直通; 1:反相
/**
 * @brief
 *
 * @param
 * @return
 */
void LED_Controller_Init(void)
{
    // led clk
    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);

    // led data
    // LED 0
    GPIOA_ModeCfg(GPIO_Pin_0, GPIO_ModeOut_PP_5mA);
    // LED 1
    GPIOA_ModeCfg(GPIO_Pin_1, GPIO_ModeOut_PP_5mA);
    // LED 2
    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeOut_PP_5mA);
    // LED 3
    GPIOA_ModeCfg(GPIO_Pin_3, GPIO_ModeOut_PP_5mA);
    // lED 4
    GPIOA_ModeCfg(GPIO_Pin_5, GPIO_ModeOut_PP_5mA);
    // lED 5
    GPIOA_ModeCfg(GPIO_Pin_6, GPIO_ModeOut_PP_5mA);
    // LED6、LED7 闲置（HUB75E只用6路）
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);

    // 配置分频和模式选择
    ch58x_led_controller_init(LED_MODE, LED_CLK_DIV);
}

/* 行地址配置 */
void LED_Row_Address_Init(void)
{
    // 1. 先设置安全的初始电平（引脚已改至 PB8=OE, PB7=LAT）
    GPIOB_SetBits(GPIO_Pin_8);   // OE 置高：关闭显示输出，防止初始化乱码闪烁
    GPIOB_ResetBits(GPIO_Pin_7); // LAT 置低：锁存信号平时保持低电平

    // 2. 配置引脚为 5mA 推挽输出模式
    // 行地址 A~E (PA9 ~ PA13)
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);  // A
    GPIOA_ModeCfg(GPIO_Pin_10, GPIO_ModeOut_PP_5mA); // B
    GPIOA_ModeCfg(GPIO_Pin_11, GPIO_ModeOut_PP_5mA); // C
    GPIOA_ModeCfg(GPIO_Pin_12, GPIO_ModeOut_PP_5mA); // D
    GPIOA_ModeCfg(GPIO_Pin_13, GPIO_ModeOut_PP_5mA); // E

    // 控制信号 LAT 和 OE (PB7 ~ PB8)
    GPIOB_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA); // LAT
    GPIOB_ModeCfg(GPIO_Pin_8, GPIO_ModeOut_PP_5mA); // OE
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main()
{
    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(SYSCLK_FREQ);
    /* 配置串口调试 */
    DebugInit();
    PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);
    PRINT("调试初始化完成\n");

    LED_Controller_Init();
    PRINT("LED_Controller_Init\n");
    LED_Row_Address_Init();
    PRINT("LED_Row_Address_Init\n");
    // 填充红色/绿色测试数据
    Fill_Test_Data();
    PRINT("Fill_Test_Data\n");

    // 设置行地址为0
    GPIOA_ResetBits(GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13);

    // TMR_DMACfg 预发送已移除：会在 LED_ENABLE 前触发 DMA，污染完成标志

#if LSB_HSB // LSB HSB
    R8_LED_CTRL_MOD ^= RB_LED_BIT_ORDER;
#endif

#if POLAR // 极性
    R8_LED_CTRL_MOD ^= RB_LED_OUT_POLAR;
#endif

    LED_ENABLE();
    // 采用 while 中的轮询死等待，千万不要去开启它！关掉 NVIC 的中断。
    // PFIC_EnableIRQ(LED_IRQn);

    PRINT("LED循环开始!!\n");

    // 先拉高 OE，防止移位过程中显示乱码
    GPIOB_SetBits(GPIO_Pin_8);

    // ---- 发送一帧并锁存 ----
    R8_LED_CTRL_MOD &= ~RB_LED_DMA_EN;
    R32_LED_DMA_BEG = ((uint32_t)row_data & RB_LED_DMA_BEG);
    R16_LED_DMA_LEN = HUB75_COLS; // 64 个 uint32_t（单位确认：1 uint32_t = 1 pixel）
    R8_LED_CTRL_MOD |= RB_LED_DMA_EN;
    while (!(R16_LED_STATUS & RB_LED_IF_DMA_END));
    R16_LED_STATUS = RB_LED_IF_DMA_END;

    GPIOB_SetBits(GPIO_Pin_7);    // LAT 拉高
    __asm volatile("nop");
    __asm volatile("nop");
    GPIOB_ResetBits(GPIO_Pin_7);  // LAT 拉低

    // ---- OE 极性探测循环 ----
    // 看串口提示，记录屏幕亮起时对应的 OE 状态
    PRINT("OE 极性探测开始\n");
    while (1)
    {
        GPIOB_SetBits(GPIO_Pin_8);   // OE = HIGH
        PRINT("OE HIGH\n");
        DelayMs(600);

        GPIOB_ResetBits(GPIO_Pin_8); // OE = LOW
        PRINT("OE LOW\n");
        DelayMs(600);
    };
}

// /*********************************************************************
//  * @fn      LED_IRQHandler
//  *
//  * @brief   LED中断函数
//  *
//  * @return  none
//  */
// __INTERRUPT
// __HIGH_CODE
// void LED_IRQHandler(void)
// {
//     // 清空中断标志
//     if (LED_GetITFlag(RB_LED_IF_DMA_END)) // 获取中断标志
//     {
//         LED_ClearITFlag(RB_LED_IF_DMA_END); // 清除中断标志
//         ch58x_led_controller_send(row_data, 16);
//     }
// }
