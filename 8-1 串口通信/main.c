#include <REGX52.H>
#include "intrins.h"
#include "UART.h"
#include "Delay.h"

unsigned char num;

void main()
{
	UartInit();
	
	while(1)
	{
		sendByte(num);
		num++;
		DelayMs(1000);
	}
}

