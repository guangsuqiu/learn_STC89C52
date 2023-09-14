#include <STC89C5xRC.H>
#include <intrins.h> //使用_nop_();所添加的头文件

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

main()
{
	while(1)
	{
		P20=0;
		Delay1000ms();
		P20=1;
		Delay1000ms();
	}
}