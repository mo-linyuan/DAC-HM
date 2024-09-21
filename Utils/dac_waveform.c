#include "dac_waveform.h"
#include "dac_font.h"
#include "DAC8563.h"
#include "Tmux6119.h"

DAC_WAVEFORM dac_waveform={0,false,0};

//reset脉冲
void reset(int table[], int size) {
    static int vol_count = 0;
    if (dac_waveform.flagdac == true) {
            WriteData_OUTA(table[vol_count]);
            vol_count++;
            if (vol_count == size) {
                WriteData_OUTA(0);
                dac_waveform.flagdac = false;
                vol_count = 0;
            }
        }
    }

//编程脉冲
void DAC_OUT(int table[], int size) {
    static int vol_count = 0;        // 当前脉冲序号
    static int wave_state = 0;       // 脉冲输出状态
    if (dac_waveform.flagdac == true) {
        switch (wave_state) {
            case 0: // 输出脉冲
                WriteData_OUTA(table[vol_count]);
                wave_state = 1;     // 转到输出0电平状态
                break;
            case 1: // 输出0电平
                WriteData_OUTA(0);
                vol_count++;
                // 每输出3个脉冲后，插入一个reset
                if (vol_count % 3 == 0) {
                    wave_state = 2;  // 转到输出reset的状态
                } else {
                    wave_state = 0;  // 回到输出下一个脉冲的状态
                }
                break;
            case 2: // 输出-200
                WriteData_OUTA(-1000);

                if (vol_count == size) {     // 所有脉冲输出完毕，重置
                    WriteData_OUTA(0);
                    dac_waveform.flagdac = false;
                    vol_count = 0;
                    wave_state = 0;
                }
                wave_state = 0;     // 回到输出下一个脉冲的状态
                break;
            default:
                dac_waveform.flagdac=false;
                break;
        }
    }
}


void pulse_mod(){
    switch (dac_waveform.mod) {
        case 0XF0:
            reset(triangle_A0,21);
            break;
        case 0XF1:
            reset(pulse_1111,8);
            break;
        case 0X30:
            DAC_OUT(table_mask3_0,33);
            break;
        case 0X31:
            DAC_OUT(table_mask3_1,1500);
            break;
        case 0X32:
            DAC_OUT(table_mask3_2,1500);
            break;
        case 0X33:
            DAC_OUT(table_mask3_3,1500);
            break;
        case 0X34:
            DAC_OUT(table_mask3_4,1500);
            break;
        case 0X35:
            DAC_OUT(table_mask3_5,1500);
            break;
        case 0X36:
            DAC_OUT(table_mask3_6,1500);
            break;
        default:
            dac_waveform.flagdac=false;
            break;
    }
}



