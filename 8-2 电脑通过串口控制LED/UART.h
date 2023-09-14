#ifndef __UART_H__
#define __UART_H__
#include <STC89C5xRC.H>
#include "intrins.h"

void UartInit(void);		//9600bps@11.0592MHz
void sendByte(unsigned char Byte);


/**

void UART_Routime(void) interrupt 4
{
	if(RI==1)
	{
		num=SBUF;
		P2=~num;
		sendByte(num);
		RI=0; // 接受结束
	}
}

*/


#endif