//
// Created by Linyuan Mo on 24-6-8.
//

#include "usart_utilize.h"
#include "usart_handle.h"
#include "dac_waveform.h"
#include "tim_handle.h"
/*指令集合
 #--------- USART1_RX_BUF[0]---------#
 FE:脉冲开关
 #--------- USART1_RX_BUF[1]---------#
 A0:模拟开关打开，其余指令关闭
 F0:reset脉冲
 F1:1111脉冲
 31:table_mask3_1
 32:table_mask3_2
 33:table_mask3_3
 34:table_mask3_4
 35:table_mask3_5
 36:table_mask3_6
*/

uint8_t t;
uint8_t len;
uint8_t trigger;
uint8_t pulse_width;
void uart1_handle(void) {
    if (USART_RX_STA & 0x8000)//串口1判断中断接收标志位
    {
        len = USART_RX_STA & 0x3fff; // 获取接收到的数据长度
        for (t = 0; t < len; t++) {
            printf("%02x", USART1_RX_BUF[t]);
        }
        printf("\r\n");

        while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TC) == RESET);// 等待所有数据发送完成
        trigger=USART1_RX_BUF[0];
        dac_waveform.mod=USART1_RX_BUF[1];
        pulse_width = USART1_RX_BUF[2];	//脉冲宽度
        TIM2_update(pulse_width);
        USART_RX_STA = 0; //复位接收标志
    }

    if (trigger == 0xFE) {
        dac_waveform.flagdac = true;
        trigger=0xff;
    }

}




