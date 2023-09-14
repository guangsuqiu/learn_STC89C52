#include <STC89C5xRC.H>
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
	P20=0;
	while(1)
	{
		if(P31==0)
		{
			Delay(20);
			while(P31==0);
			Delay(20);
			
			if(num==7)
				num=0;
			else
				num++;
			
			P2=~(0x1<<num);
		}
		else if(P30==0)
		{
			Delay(20);
			while(P30==0);
			Delay(20);
			
			if(num==0)
				num=7;
			else
				num--;
			
			P2=~(0x1<<num);
		}
	}
}