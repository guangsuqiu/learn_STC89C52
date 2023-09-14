
#include "Delay.h"
void DelayMs(unsigned char ms)		//@11.0592MHz
{
	while(ms--)
	{
		unsigned char data i, j;

		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Delayus(unsigned char us)		//@11.0592MHz
{
	while(us--)
	{
	_nop_();
	_nop_();
	_nop_();
	}
}
