#include "BULETOOTH.h"

/*
	目前仅实现了从模式功能（蓝牙透传），如果需要对蓝牙模块进行配置
	需要单片机使能蓝牙EN引脚，然后通过AT指令对蓝牙模块进行控制
*/


void HC08_Init(void)
{
	UartInit();
}


void HC08_SentData(unsigned char *head)
{
	while(*head) // '\0'
	{
		sendByte(*head);
		head=head+1;
	}
}

