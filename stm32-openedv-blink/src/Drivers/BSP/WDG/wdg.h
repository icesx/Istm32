/**
 ****************************************************************************************************
 * @file        iwdg.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-22
 * @brief       独立看门狗 驱动代码
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
 * 修改说明
 * V1.0 20211124
 * 第一次发布
 *
 ****************************************************************************************************
 */

#ifndef __WDG_H
#define __WDG_H

#include "sys.h"


void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);

#endif




























