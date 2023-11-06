#include <REGX52.H>
#include <intrins.h>

void Delay(unsigned int ms)		//@11.0592MHz
{
	while(ms--)
	{
		unsigned char i, j;

//		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	unsigned char num=0;
	P2_0=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			if(num==7)
				num=0;
			else
				num++;
			
			P2=~(0x1<<num);
		}
		else if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			if(num==0)
				num=7;
			else
				num--;
			
			P2=~(0x1<<num);
		}
	}
}