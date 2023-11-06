#include <REGX52.H>
#include "intrins.h"
#include "UART.h"

unsigned char num;

void main()
{
	UartInit();
	
	while(1)
	{

	}
}

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