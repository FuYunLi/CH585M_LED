/********************************** (C) COPYRIGHT *******************************
* File Name          : ch58x_drv_ledc.c
* Author             : WCH
* Version            : V1.0
* Date               : 2024/11/20
* Description        : LED驱动相关
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "ch58x_drv_ledc.h"

/*********************************************************************
 * @fn      ch58x_led_controller_init
 *
 * @brief   LED初始化
 *
 * @return  none
 */
void ch58x_led_controller_init(ch58x_led_out_mode_t mode, uint8_t led_clk_div)
{
    R8_LED_CLOCK_DIV  = led_clk_div;
    R8_LED_CTRL_MOD1  = 0;                    // 清除 DMA_LOOP 位，确保单次模式
    R8_LED_CTRL_MOD   = RB_LED_ALL_CLEAR;     // Pulse: 强制清空 FIFO/计数器/中断标志
    R8_LED_CTRL_MOD   = (mode << 6);          // 清掉 ALL_CLEAR，写入通道模式（复位后位序默认0=MSB优先）
}

/*********************************************************************
 * @fn      ch58x_led_controller_send
 *
 * @brief   LED数据使用DMA发送
 *
 * @return  none
 */
void ch58x_led_controller_send(uint32_t *data, uint16_t length)
{
    R32_LED_DMA_BEG = ((uint32_t)(data) & RB_LED_DMA_BEG);
    R16_LED_DMA_LEN = length;
    R8_LED_CTRL_MOD |= RB_LED_DMA_EN;
}

/*********************************************************************
 * @fn      LED_DMACfg
 *
 * @brief   配置DMA功能
 *
 * @param   s           - 是否打开DMA功能
 * @param   startAddr   - DMA 起始地址
 * @param   len         - DMA 发送长度
 * @param   m           - 配置DMA模式
 *
 * @return  none
 */
void TMR_DMACfg(uint8_t s, uint32_t startAddr, uint16_t len, DMAModeTypeDef m)
{
    if(s == DISABLE)
    {
        R8_LED_CTRL_MOD &= ~RB_LED_DMA_EN;
    }
    else
    {
        R32_LED_DMA_BEG = ((uint32_t)(startAddr)& RB_LED_DMA_BEG);
        R16_LED_DMA_LEN = len;
        if(m)
        {
            R8_LED_CTRL_MOD1 = RB_LED_DMA_LOOP;
            R8_LED_CTRL_MOD |= RB_LED_DMA_EN;
        }
        else
            R8_LED_CTRL_MOD |= RB_LED_DMA_EN;
    }
}
