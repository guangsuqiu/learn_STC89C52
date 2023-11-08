#include <REGX52.H>
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
		P2_0=0;
		Delay1000ms();
		P2_0=1;
		Delay1000ms();
	}
}