
#include "intrins.h"
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