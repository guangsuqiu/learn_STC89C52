#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "Timer0.h"
#include "Nixie.h"
#include "key.h"

sbit Motor=P1^0;

unsigned char Counter,Compare,KeyNum,Speed;

void main()
{
	Timer0_Init();	
	while(1)
	{
		KeyNum=key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0)
			{
				Compare=0;
			}
			if(Speed==1)
			{
				Compare=50;
			}
			if(Speed==2)
			{
				Compare=75;
			}
			if(Speed==3)
			{
				Compare=100;
			}
		}
		Nixie(1,Speed);
	}
}

void Timer0_Rountine(void)  interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
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