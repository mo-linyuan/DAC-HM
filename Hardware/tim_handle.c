#include "tim_handle.h"
#include "tim.h"
#include "dac_waveform.h"

//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        pulse_mod();
	 
    }
}

void TIM2_update(uint8_t arr)
{
    htim2.Init.Period = arr-1;  // 修改定时器周期

    // 重新初始化定时器，以应用新的周期参数
    if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }
}
