
#include "key.h"
#include <REGX52.H>
#include <INTRINS.H>
void DelayMs(int k)		//@11.0592MHz
{
	while(k--)
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


unsigned char key(void)
{
	unsigned char KeyNumber=0;
	if(P3_1==0){DelayMs(20);while(P3_1==0);DelayMs(20);KeyNumber=1;}
	if(P3_0==0){DelayMs(20);while(P3_0==0);DelayMs(20);KeyNumber=2;}
	if(P3_2==0){DelayMs(20);while(P3_2==0);DelayMs(20);KeyNumber=3;}
	if(P3_3==0){DelayMs(20);while(P3_3==0);DelayMs(20);KeyNumber=4;}
	return KeyNumber;
}

