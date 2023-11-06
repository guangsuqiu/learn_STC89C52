#include "Timer0.h"


void Timer0_Init(void)	// 1ms 11.0592MHz
{
    TMOD&=0xf0;
    TMOD|=0x01;
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
    TF0=0;
	TR0=0;
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}