//
// Created by Linyuan Mo on 24-6-8.
//

#include "Tmux6119.h"
#include "dac_waveform.h"

void SEL1(uint8_t SEL1)
{
    if (SEL1 == 1) {
        HAL_GPIO_WritePin(SEL1_GPIO_Port, SEL1_Pin, GPIO_PIN_SET);  // 闭合
    } else {
        HAL_GPIO_WritePin(SEL1_GPIO_Port, SEL1_Pin, GPIO_PIN_RESET);  // 断开
    }
}

//单个神经元测试
void Tmax_state(void)
{
    if(dac_waveform.mod == 0xF0){
        SEL1(1);//闭合
        LED1(0);//亮

    }
    else{
        SEL1(0);//断开
        LED1(1);//灭
    }
}
