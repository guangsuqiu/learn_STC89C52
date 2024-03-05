#ifndef __UART_H__
#define __UART_H__

#include "define.h"

void UartInit(void);		//9600bps@11.0592MHz
void sendByte(unsigned char Byte);

#endif