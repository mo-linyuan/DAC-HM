#ifndef __USART_HANDLE_H
#define __USART_HANDLE_H
#include "stdio.h"
#include "stm32f4xx_hal.h" //HAL库文件声明



#define False 0
#define True 1
#define ADDRESS_ID 0xA1

#define USART1_REC_LEN  			200  		//定义最大接收字节数 200
#define EN_USART1_RX 			1			//使能（1）/禁止（0）串口1接收
	  	
extern uint8_t  USART1_RX_BUF[USART1_REC_LEN]; 	//接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern uint8_t UART1_Rx_Len;
extern uint8_t UART1_Sender_Address;
extern uint8_t UART1_Rx_Data[USART1_REC_LEN];
extern uint8_t UART1_Updated_Flag;
extern uint16_t USART_RX_STA;
extern uint8_t USART1_NewData;//当前串口中断接收的1个字节数据的缓存


extern UART_HandleTypeDef UART1_Handler; 	//UART句柄

#define RXBUFFERSIZE   1 					//缓存大小
extern uint8_t aRxBuffer[RXBUFFERSIZE];			//HAL库USART接收Buffer

//如果想串口中断接收，请不要注释以下宏定义
void uart_init(uint32_t bound);
#endif
