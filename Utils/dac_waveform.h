#ifndef DAC_WAREFORM_H
#define DAC_WAREFORM_H

#include "stdio.h"
#include "stdbool.h"
#include "DAC8563.h"

#define POINT_NUM 1500


typedef struct{
    uint32_t count;
    bool flagdac;
    int mod;
}DAC_WAVEFORM;

extern DAC_WAVEFORM dac_waveform;
extern int table_mask3_0[];
extern int table_mask3_1[POINT_NUM];
extern int table_mask3_2[POINT_NUM];
extern int table_mask3_3[POINT_NUM];
extern int table_mask3_4[POINT_NUM];
extern int table_mask3_5[POINT_NUM];
extern int table_mask3_6[POINT_NUM];
extern int triangle_A0[];
extern int pulse_1111[];

void DAC_OUT(int table[],int num);
void pulse_mod();


#endif

