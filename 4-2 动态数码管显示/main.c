#include <STC89C5xRC.H>
#include <stdio.h>

void DelayMs(unsigned char ms)		//@12.000MHz
{
	while(ms--)
	{
		unsigned char i, j;

		i = 16;
		j = 147;
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
		case 1:P24=0;P23=0;P22=0;break;
		case 2:P24=0;P23=0;P22=1;break;
		case 3:P24=0;P23=1;P22=0;break;
		case 4:P24=0;P23=1;P22=1;break;
		case 5:P24=1;P23=0;P22=0;break;
		case 6:P24=1;P23=0;P22=1;break; 
		case 7:P24=1;P23=1;P22=0;break;
		case 8:P24=1;P23=1;P22=1;break;
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