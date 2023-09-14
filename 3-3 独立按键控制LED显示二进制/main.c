#include <STC89C5xRC.H>
#include <intrins.h>

void Delay(unsigned int ms)		//@11.0592MHz
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

void main()
{
	unsigned char num=0;
	while(1)
	{
		if(P31==0)//按键按下 引脚拉低
		{
			Delay(20);
			while(P31==0);//按键松开 打破循环
			Delay(20);
			
			num++;
			P2=~num;//P2长度固定 即使num超过256 但对P2赋值只能赋八位
		}
	}
}