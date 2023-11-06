
#include <REGX52.H>

void Timer0_Init(void)	// 1ms 12MHz
{
    // 选择Timer0 为模式1
    TMOD&=0xf0;
    TMOD|=0x01;
    // 初始化中断溢出标志位 溢出时自动设为1 等待中断响应后自动设为0
    TF0=0;
    // 初始化计数器数据
    // 1. 计数器低八位
    TL0=64536%0x100;
    // 2. 计数器高八位
    TH0=64536/0x100;
    // 开始计时
    TR0=1;
    // 开启中断
    ET0=1;
    // 开启总中断开关
    EA=1;
    // 选择中断优先级为低优先级
    PT0=0;
}

//void Timer0_Rountine(void)  interrupt 1
//{
//	static unsigned int i;
//	i++;
//    // 1. 计数器低八位
//    TL0=64536%0x100;
//    // 2. 计数器高八位
//    TH0=64536/0x100;
//	if(i>=300)
//	{
//		i=0;
//		if(LedMode==0)
//		{
//			P2=_crol_(P2,1); // 循环移位函数
//		}
//		if(LedMode==1)
//		{
//			P2=_cror_(P2,1);
//		}
//	}
//}
