#ifndef __ONEWRIE_H__
#define __ONEWRIE_H__

#include <REGX52.H>
#include "intrins.h"

sbit OneWire_DQ=P3^7;
unsigned char OneWire_Init(void);
unsigned char OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte(void);

#endif