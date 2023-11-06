#ifndef __IIC_H__
#define __IIC_H__

#include <REGX52.H>
#include "intrins.h"

sbit I2C_SCL =P2^1;
sbit I2C_SDA =P2^0;

// 开始
void IIC_Start(void);
// 结束
void IIC_Stop(void);
// 发送一个字节
void IIC_SendByte(unsigned char byte);
// 接收一个字节
unsigned char IIC_ReciveByte(void);
// 发送应答
void IIC_SendArk(bit Bit);
// 接受应答
bit IIC_ReciveArk(void);

#endif