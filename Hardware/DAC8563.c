//
// Created by Linyuan Mo on 24-6-8.
//

#include "DAC8563.h"

void DAC8563_WRITE(uint8_t cmd, uint16_t data)
{
    uint8_t s = 0;
    SYNC_H;
    //  delay_us(4);
    SYNC_L;
    SCLK_L;
    for (s = 0; s < 8; s++)
    {
        if ((cmd & 0x80) == 0x80)
        {
            DIN_H;
        }
        else
        {
            DIN_L;
        }
        //    delay_us(4);
        SCLK_H;
        //    delay_us(4);
        cmd <<= 1;
        SCLK_L;
        //    delay_us(4);
    }
    for (s = 0; s < 16; s++)
    {
        if ((data & 0x8000) == 0x8000)
        {
            DIN_H;
        }
        else
        {
            DIN_L;
        }
        //    delay_us(4);
        SCLK_H;
        //    delay_us(4);
        data <<= 1;
        SCLK_L;
        //    delay_us(4);
    }
}

void DAC8563_Init(void)
{
    CLR_L;
    LDAC_H;
    MX_GPIO_Init();
    DAC8563_WRITE(CMD_RESET_ALL_REG, DATA_RESET_ALL_REG);	  // 复位
    DAC8563_WRITE(CMD_PWR_UP_A_B, DATA_PWR_UP_A_B);			  // 上电DAC-A和DAC-B
    DAC8563_WRITE(CMD_INTERNAL_REF_EN, DATA_INTERNAL_REF_EN); // 启用内部参考和复位DAC以获得增益= 2
    DAC8563_WRITE(CMD_GAIN, DATA_GAIN_B2_A2);				  // Set Gains A 10V  B 10V
}

//=============================================
//
//	设置并更新DAC输出电压（更改模块跳线帽及设置DAC8563内部增益 可设置不同输出范围 ）
//
//	参数：data_a为A路输出，data_b为B路输出
//
//=============================================
void DAC_OutAB(uint16_t data_a, uint16_t data_b)
{
    DAC8563_WRITE(CMD_SETA_UPDATEA, data_a);
    DAC8563_WRITE(CMD_SETB_UPDATEB, data_b);
    LDAC_L;
    //  delay_us(4);
    LDAC_H;
}

void DAC_OutA(uint16_t data_a)
{
    DAC8563_WRITE(CMD_SETA_UPDATEA, data_a);
    LDAC_L;
    LDAC_H;
}

void DAC_OutB(uint16_t data_b)
{
    DAC8563_WRITE(CMD_SETB_UPDATEB, data_b);
    LDAC_L;
    LDAC_H;
}
//=============================================

void WriteData_OUTA(int Vout) //电压单位为mv
{
    uint16_t Dn;
    Dn=(Vout+10000)*65536/20000;
    DAC_OutA(Dn);
}
