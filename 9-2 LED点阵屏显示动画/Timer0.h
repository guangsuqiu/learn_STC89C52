#ifndef __TIMER0_H__
#define __TIMER0_H__

void Timer0Init(void); // 1ms

/*
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
*/

#endif