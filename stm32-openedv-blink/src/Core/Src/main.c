/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-20
 * @brief       跑马灯 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */
#include "led.h"
#include "thesys.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"
#include "key.h"


int main(void)
{
    uint8_t key;

    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    led_init();                         /* 初始化LED */
    beep_init();                        /* 初始化蜂鸣器 */
    key_init();                         /* 初始化按键 */
    LED0(0);                            /* 先点亮LED0 */

    while (1)
    {
        key = key_scan(0); /* 得到键值 */

        if (key)
        {
            switch (key)
            {
            case WKUP_PRES:    /* 控制蜂鸣器 */
                BEEP_TOGGLE(); /* BEEP状态取反 */
                break;

            case KEY1_PRES:    /* 控制LED1(GREEN)翻转 */
                LED1_TOGGLE(); /* LED1状态取反 */
                break;

            case KEY0_PRES:    /* 同时控制LED0, LED1翻转 */
                LED0_TOGGLE(); /* LED0状态取反 */
                LED1_TOGGLE(); /* LED1状态取反 */
                break;
            }
        }
        else
        {
            delay_ms(10);
        }
    }
}
