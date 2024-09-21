//
// Created by Linyuan Mo on 24-6-8.
//

#include "LED.h"

void LED0(uint8_t LED0)
{
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, LED0);
}

void LED1(uint8_t LED1)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, LED1);
}

