#include "AT24C02.h"

// 随机读
unsigned char AT24C02_Read(unsigned char addr)
{
    unsigned char Byte=0x00;
    IIC_Start();
    IIC_SendByte(0xA0);
    IIC_ReciveArk();
    IIC_SendByte(addr);
    IIC_ReciveArk();
    IIC_Start();
    IIC_SendByte(0xA1);
    IIC_ReciveArk();
    Byte=IIC_ReciveByte();
    IIC_SendArk(1);
    IIC_Stop();
    return Byte;
}


// 字节写
void AT24C02_Write(unsigned char addr,Byte)
{
    IIC_Start();
    IIC_SendByte(0xA0);
    IIC_ReciveArk();
    IIC_SendByte(addr);
    IIC_ReciveArk();
    IIC_SendByte(Byte);
    IIC_ReciveArk();
    IIC_Stop();
}