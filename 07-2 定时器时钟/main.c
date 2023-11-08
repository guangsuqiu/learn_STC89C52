#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Hour,Min,S;

void main()
{
	LCD_Init();
	Timer0Init();
	while(1)
	{
		LCD_ShowNum(1,1,Hour,2);
		LCD_ShowNum(1,4,Min,2);
		LCD_ShowNum(1,7,S,2);
	}
}

void Timer0_Rountine(void)  interrupt 1
{
	static unsigned int i;
	i++;
    // 1. 计数器低八位
    TL0=64536%0x100;
    // 2. 计数器高八位
    TH0=64536/0x100;
	if(i>=1000)
	{
		i=0;
		S++;
		if(S==60)
		{
			Min++;
			S=0;
			if(Min==60)
			{
				Hour++;
				Min=0;
				if(Hour==24)
				{
					Hour=0;
				}
			}
		}
	}
}