//
// Created by Linyuan Mo on 24-6-8.
//
#include "usart_handle.h"
#include "usart.h"

uint8_t USART1_RX_BUF[USART1_REC_LEN];
uint16_t USART_RX_STA=0;
uint8_t USART1_NewData;

void  HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart)
{
    if(huart ==&huart1)
    {
        if((USART_RX_STA&0x8000)==0){
            if(USART_RX_STA&0x4000){
                if(USART1_NewData!=0x0a)USART_RX_STA=0;
                else USART_RX_STA|=0x8000;
            }else{
                if(USART1_NewData==0x0d)USART_RX_STA|=0x4000;
                else{
                    USART1_RX_BUF[USART_RX_STA&0X3FFF]=USART1_NewData;
                    USART_RX_STA++;
                    if(USART_RX_STA>(USART1_REC_LEN-1))USART_RX_STA=0;
                }
            }
        }
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&USART1_NewData, 1);
    }
}

