#include "key.h"

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	if(GPIOx == WKUP_GPIO_Port)
	{
		if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin))
		{
			HAL_Delay(10); //10ms
			if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin))
			{
				while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin));     
				return KEY_ON;
			}
		}
		/* 按键没被按下，返回没被按下状态 */
		return KEY_OFF;
	}
	else
	{
		if(!HAL_GPIO_ReadPin(GPIOx,GPIO_Pin))
		{
			HAL_Delay(10); //10ms
			if(!HAL_GPIO_ReadPin(GPIOx,GPIO_Pin))
			{
				while(!HAL_GPIO_ReadPin(GPIOx,GPIO_Pin));     
				return KEY_ON;
			}
		}
  
		return KEY_OFF;
	}
  
}