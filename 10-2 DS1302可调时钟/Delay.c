
#include "Delay.h"
void DelayMs(unsigned int ms)		//@11.0592MHz
{
	while(ms--)
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
}

void Delayus(unsigned int us)		//@11.0592MHz
{
	while(us--)
	{	
		_nop_();
	}
}
