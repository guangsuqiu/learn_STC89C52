#include "Delay.h"

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void DelayMs(unsigned char ms)		//@11.0592MHz
{
	while(ms--)
	{
		Delay1ms();
	}
}
