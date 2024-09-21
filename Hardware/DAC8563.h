//
// Created by Linyuan Mo on 24-6-8.
//

#ifndef _DAC8563_H
#define _DAC8563_H

#include <stdint.h>
#include "stdbool.h"
#include "gpio.h"
#define SCLK_H       HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET)
#define SYNC_H       HAL_GPIO_WritePin(SYNC_GPIO_Port, SYNC_Pin, GPIO_PIN_SET)
#define CLR_H        HAL_GPIO_WritePin(CLR_GPIO_Port, CLR_Pin, GPIO_PIN_SET)
#define LDAC_H       HAL_GPIO_WritePin(LDAC_GPIO_Port, LDAC_Pin, GPIO_PIN_SET)
#define DIN_H        HAL_GPIO_WritePin(DIN_GPIO_Port, DIN_Pin, GPIO_PIN_SET)

#define SCLK_L       HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET)
#define SYNC_L       HAL_GPIO_WritePin(SYNC_GPIO_Port, SYNC_Pin, GPIO_PIN_RESET)
#define CLR_L        HAL_GPIO_WritePin(CLR_GPIO_Port, CLR_Pin, GPIO_PIN_RESET)
#define LDAC_L       HAL_GPIO_WritePin(LDAC_GPIO_Port, LDAC_Pin, GPIO_PIN_RESET)
#define DIN_L        HAL_GPIO_WritePin(DIN_GPIO_Port, DIN_Pin, GPIO_PIN_RESET)


#define CMD_SETA_UPDATEA      		0x18	// 写入DAC-A输入寄存器并更新DAC-A +16位数据
#define CMD_SETB_UPDATEB      		0x19	// 写入DAC-B输入寄存器并更新DAC-B +16位数据
#define CMD_UPDATE_ALL_DACS	   		0x0F	// 更新所有DAC 后16位只需时钟即可

// Gain
#define CMD_GAIN	    					0x02	// default with internal Vref
#define DATA_GAIN_B2_A2    			0x00	// 增益：DAC-B增益= 2，DAC-A增益= 2（默认为内部VREF）
#define DATA_GAIN_B2_A1       		0x01	// 增益：DAC-B增益= 2，DAC-A增益= 1
#define DATA_GAIN_B1_A2         	0x02	// 增益：DAC-B增益= 1，DAC-A增益= 2
#define DATA_GAIN_B1_A1       		0x03	// 增益：DAC-B增益= 1，DAC-A增益= 1（上电默认值）

#define CMD_PWR_UP_A_B		      	0x20	// 设置DAC上电或掉电模式
#define DATA_PWR_UP_A		      	  0x0001	// 上电DAC-A
#define DATA_PWR_UP_B		      	  0x0002	// 上电 DAC-B
#define DATA_PWR_UP_A_B		      	0x0003	// 上电DAC-A和DAC-B
#define DATA_PWR_DOWN1_A		      0x0041	// 关断DAC-A; 1kΩ至GND
#define DATA_PWR_DOWN1_B		      0x0042	// 关断DAC-B; 1kΩ至GND
#define DATA_PWR_DOWN1_A_B		      0x0043	// 关断DAC-A和DAC-B; 1kΩ至GND
#define DATA_PWR_DOWN2_A		      	0x0081	// 关断DAC-A; 100kΩ至GND
#define DATA_PWR_DOWN2_B		      	0x0082	// 关断DAC-B; 100kΩ至GND
#define DATA_PWR_DOWN2_A_B		      0x0083	// 关断DAC-A和DAC-B; 100kΩ至GND
#define DATA_PWR_DOWN3_A		      	0x00C1	// 关断DAC-A; 高阻
#define DATA_PWR_DOWN3_B		      	0x00C2	// 关断DAC-B; 高阻
#define DATA_PWR_DOWN3_A_B		      0x00C3	// 关断DAC-A和DAC-B;高阻


#define CMD_RESET_ALL_REG	      	0x28	// Software reset
#define DATA_RESET_ALL_REG     		0x0001	// 复位所有寄存器并更新所有DAC（上电复位更新）
#define DATA_RESET_ADCAB     		0x0000 //复位DAC-A和DAC-B输入寄存器并更新所有DAC


#define CMD_LDAC_DIS	        	0x30	// 设置LDAC寄存器
#define DATA_LDAC_AB       		0x0000 //LDAC引脚有效用于DAC-B和DAC-A
#define DATA_LDAC_B       		0x0001 //LDAC引脚有效用于DAC-B; 对DAC-A无效
#define DATA_LDAC_A       		0x0002  //LDAC引脚对DAC-B无效; DAC-A有效
#define DATA_LDAC_NAB       		0x0003 //LDAC引脚对DAC-B和DAC-A无效

#define CMD_INTERNAL_REF_DIS    	0x38	// Disable internal reference and reset DACs to gain = 1
#define DATA_INTERNAL_REF_DIS    	0x0000	// 禁用内部参考并将DAC复位为增益= 1

#define CMD_INTERNAL_REF_EN       0x38	// Enable Internal Reference & reset DACs to gain = 2
#define DATA_INTERNAL_REF_EN    	0x0001	//启用内部参考和复位DAC以获得增益= 2

void DAC8563_Init(void);
void DAC8563_WRITE(uint8_t cmd,uint16_t data);
void DAC_OutAB(uint16_t data_a, uint16_t data_b);
void DAC_OutA(uint16_t data_a);
void DAC_OutB(uint16_t data_b);
void WriteData_OUTA(int Vout);

#endif
