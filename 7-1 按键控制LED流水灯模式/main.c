
#include <STC89C5xRC.H>
#include "Timer0.h"
#include "key.h"
#include "intrins.h"


unsigned char KeyNum,LedMode;

void main()
{
	P2=0xFE;
	Timer0Init();
	while(1)
	{
		KeyNum=key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LedMode++;
				if(LedMode>=2)
				{
					LedMode=0;
				}
			}
		}
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
	if(i>=300)
	{
		i=0;
		if(LedMode==0)
		{
			P2=_crol_(P2,1); // 循环移位函数
		}
		if(LedMode==1)
		{
			P2=_cror_(P2,1);
		}
	}
}