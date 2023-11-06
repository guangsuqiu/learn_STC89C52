#include <REGX52.H>
#include "intrins.h"

sbit LED=P2^0;

void Delay(unsigned int t)
{
	while(t--);
}

void main()
{
	unsigned char time,t;
	while(1)
	{
		for(time=0;time<100;time++)
		{
			for(t=0;t<20;t++)
			{
				LED=0;
				Delay(time);
				LED=1;
				Delay(100-time);
			}
		}
		for(time=100;time>0;time--)
		{
			for(t=0;t<20;t++)
			{
				LED=0;
				Delay(time);
				LED=1;
				Delay(100-time);
			}
		}
	}
}