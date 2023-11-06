#include "INT0.h"


void Int0_Init(void)
{
	IT0=1; // 下降沿触发
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;
}