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
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"
#include "key.h"

void keys(void)
{
    uint8_t key;
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
void do_usart()
{
    uint8_t len;
    uint16_t times = 0;
    if (g_usart_rx_sta & 0x8000) /* 接收到了数据? */
    {
        len = g_usart_rx_sta & 0x3fff; /* 得到此次接收到的数据长度 */
        printf("\r\n您发送的消息为:\r\n");

        HAL_UART_Transmit(&g_uart1_handle, (uint8_t *)g_usart_rx_buf, len, 1000); /* 发送接收到的数据 */
        while (__HAL_UART_GET_FLAG(&g_uart1_handle, UART_FLAG_TC) != SET)
            ;               /* 等待发送结束 */
        printf("\r\n\r\n"); /* 插入换行 */
        g_usart_rx_sta = 0;
    }
    else
    {
        times++;
        if (times % 5000 == 0)
        {
            printf("\r\n正点原子 STM32开发板 串口实验\r\n");
            printf("正点原子@ALIENTEK\r\n\r\n\r\n");
        }
        if (times % 200 == 0)
            printf("请输入数据,以回车键结束\r\n");
        if (times % 30 == 0)
            LED0_TOGGLE(); /* 闪烁LED,提示系统正在运行. */

        delay_ms(10);
    }
}

int main(void)
{

    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    led_init();                         /* 初始化LED */
    beep_init();                        /* 初始化蜂鸣器 */
    key_init();                         /* 初始化按键 */
    LED0(0);                            /* 先点亮LED0 */

    while (1)
    {
        keys();
        do_usart();
    }
}
