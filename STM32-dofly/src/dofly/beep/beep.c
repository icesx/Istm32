#include "beep.h"
#include "common.h"
#define _GPIO_X GPIOB
static void _enableE()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
}
void beep_init()
{
    MX_GPIO_Init(_GPIO_X, _enableE, GPIO_PIN_8);
}
void beep()
{
    HAL_GPIO_WritePin(_GPIO_X, GPIO_PIN_8, GPIO_PIN_SET);
}
void beep_off(){
    HAL_GPIO_WritePin(_GPIO_X, GPIO_PIN_8, GPIO_PIN_RESET);
}