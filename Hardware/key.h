#ifndef __KEY_H__
#define __KEY_H__
#include "main.h"
#define KEY_ON 2
#define KEY_OFF 3

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif
