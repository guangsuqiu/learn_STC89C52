#ifndef __UART_H__
#define __UART_H__
#include <REGX52.H>
#include "intrins.h"

void UartInit(void);		//9600bps@11.0592MHz
void sendByte(unsigned char Byte);

#endif