#include "blink.h"
#include "common.h"

static void _enableE()
{
    __HAL_RCC_GPIOE_CLK_ENABLE();
}
static void _enableB()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
}

void blinkB(uint16_t pin_state)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, pin_state);
}
void blinkE(uint16_t pin_state)
{
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, pin_state);
}
void blink_initB()
{
    MX_GPIO_Init(GPIOB, _enableB, GPIO_PIN_5);
}
void blink_initE()
{
    MX_GPIO_Init(GPIOE, _enableE, GPIO_PIN_5);
}