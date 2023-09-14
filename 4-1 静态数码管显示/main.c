#include <STC89C5xRC.H>
#include <stdio.h>

// 将数码管显示的数字保存到数组中
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#if 1
// 将数码管代码写为子函数
void Nixie(unsigned char led,num)// C51规则，未验证是否适用于c语言
{
	switch(led)
	{
		case 1:P24=0;P23=0;P22=0;break;// 个位
		case 2:P24=0;P23=0;P22=1;break;
		case 3:P24=0;P23=1;P22=0;break;
		case 4:P24=0;P23=1;P22=1;break;
		case 5:P24=1;P23=0;P22=0;break;
		case 6:P24=1;P23=0;P22=1;break; 
		case 7:P24=1;P23=1;P22=0;break;
		case 8:P24=1;P23=1;P22=1;break;
	}
	P0=NixieTable[num];
}
#endif
void main()
{	
#if 0
	// 配置138译码器 来选择LED6 输出低电平
	P24=0;
	P23=0;
	P22=0;
	// 在LED6 上显示 6
	P0=0x7D;
#endif
	// 将第一位数码管显示数字6
	Nixie(1,6);
	while(1)
	{
		
	}
}