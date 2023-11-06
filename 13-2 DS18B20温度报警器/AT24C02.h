#ifndef __AT24C02_H__
#define __AT24C02_H__

#include "IIC.h"
// 随机读
unsigned char AT24C02_Read(unsigned char addr);
// 字节写
void AT24C02_Write(unsigned char addr,Byte);

#endif