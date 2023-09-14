#ifndef __UART_H__
#define __UART_H__
#include <STC89C5xRC.H>
#include "intrins.h"

void UartInit(void);		//9600bps@11.0592MHz
void sendByte(unsigned char Byte);

#endif