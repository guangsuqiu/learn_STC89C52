#include "ADC0832.h"


/**
 void ADC0832_start();
 按照时序图所示：
 为ADC0832启动的代码，CHIP SELECT(CS)一个下降沿 
 DATA(DI)为为高电平
 CLOCK(CLK)为低电平置低
**/
void ADC0832_start()
{
	CS = 1;			//禁用ADC0832芯片
	CS = 0;			 //开始

	DI  = 1;
	CLK = 1;
	CLK = 0;		  //第一个下降沿DI为1
}
/**
 unsigned char ADC0832_read(unsigned char CHX)
	参数：CHX 表示选择芯片的通道
	返回值：获得光照强度的值，该值为0~255之间的某一个量化的数值，例如00010000 32
**/
unsigned char ADC0832_read(unsigned char CHX)		 //通道0  第二位为1，第三位为0
{							 //通道1  第二位为1，第三位为1
	unsigned char temp,i;
	ADC0832_start();
	if(CHX == 0)			  //选择通道0，下降沿触发
	{
		DI = 1;
		CLK = 1;
		CLK = 0;
		DI = 0;
		CLK = 1;
		CLK = 0;
	}
	else //选择通道1
	{
		DI = 1;
		CLK = 1;
		CLK = 0;
		DI = 1;
		CLK = 1;
		CLK = 0;
	}
	CLK  =  1;
	CLK  =  0;

	for(i =8 ;i>0 ;i--) //接受8位数从高位向低位
	{	
		temp <<= 1;		   //左移一位，是末尾为0，接受端口的数据
		DI=1;
		CLK = 1;
		if(DO)//输出给单片机，如果有1，则+1,否则不执行，默认为0
		{	
			temp = temp + 0x01;
		}
		CLK = 0;
	}
	return temp;//temp中放的数值就是光照强度了
}

// 光照强度根据25的倍数粗暴的分为了十级，略微丢失精度
unsigned char ADC0832_getLight(void)
{
	unsigned char light=0;
	light=ADC0832_read(0);
	return light/25;
}
