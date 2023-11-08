#ifndef __DZP_H__
#define __DZP_H__

#include "Delay.h"

sbit RCK=P3^5;	// PCLK
sbit SCK=P3^6;	// SRCLK
sbit SER=P3^4;	// SER

void MatrixLED_Init();
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_ShowColumn(unsigned char Colunm,Data);

#endif