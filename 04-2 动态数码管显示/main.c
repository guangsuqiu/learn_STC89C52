#include <REGX52.H>
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

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Nixie(unsigned char led,num)
{
	switch(led)
	{
		case 1:P2_4=0;P2_3=0;P2_2=0;break;
		case 2:P2_4=0;P2_3=0;P2_2=1;break;
		case 3:P2_4=0;P2_3=1;P2_2=0;break;
		case 4:P2_4=0;P2_3=1;P2_2=1;break;
		case 5:P2_4=1;P2_3=0;P2_2=0;break;
		case 6:P2_4=1;P2_3=0;P2_2=1;break; 
		case 7:P2_4=1;P2_3=1;P2_2=0;break;
		case 8:P2_4=1;P2_3=1;P2_2=1;break;
	}
	P0=NixieTable[num];
#if 1
	// 没有清零，就会出现残影和错位
	// 延时并清零 去除残影与错位的办法
	DelayMs(1);
	P0=0x00;
#endif
}

void main()
{	
	while(1)
	{
		Nixie(3,1);
		Nixie(2,2);
		Nixie(1,3);
	}
}