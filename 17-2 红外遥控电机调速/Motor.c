#include "Motor.h"

unsigned char Counter,Compare;

void Motor_Init(void)
{
	Timer1_Init();	
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}


void Timer1_Rountine(void)  interrupt 3
{
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=100;
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
}