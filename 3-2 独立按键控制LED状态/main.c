#include <STC89C5xRC.H>
#include <INTRINS.H>

void Delay1ms(unsigned int ms)	//@11.0592MHz
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
	while(1)
	{
		if(P31==0)//按键被按下
		{
			Delay1ms(20);//按下消抖20毫秒
			while(P31==0);//跳过按下的过程
			Delay1ms(20);//松开消抖20毫秒
			P20=~P20;//让LED反转状态
		}
	}
}