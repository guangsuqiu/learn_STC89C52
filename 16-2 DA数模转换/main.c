#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "Timer0.h"

sbit DA=P2^1;

unsigned char Counter,Compare,i;

void main()
{
	Timer0_Init();	
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			DelayMs(1);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;
			DelayMs(1);
		}
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
		DA=1;
	}
	else
	{
		DA=0;
	}
}