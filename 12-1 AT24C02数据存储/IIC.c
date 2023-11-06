#include "IIC.h"

// 开始
void IIC_Start(void)
{
    // 初始化
    I2C_SCL=1;
    I2C_SDA=1;
    
    I2C_SDA=0;
    I2C_SCL=0;
}

// 结束
void IIC_Stop(void)
{
    I2C_SDA=0;
    
    I2C_SCL=1;
    I2C_SDA=1;
    
}

// 发送一个字节
void IIC_SendByte(unsigned char byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        I2C_SDA=byte&(0x80>>i);
        I2C_SCL=1;
        I2C_SCL=0;
    }
}

// 接收一个字节
unsigned char IIC_ReciveByte(void)
{
    unsigned char byte=0x00,i;
    I2C_SDA=1; // 释放SDA,让从机操作
    for(i=0;i<8;i++)
    {
        I2C_SCL=1;
        if(I2C_SDA){byte|=(0x80>>i);}
        I2C_SCL=0;
    }
    return byte;
}

// 发送应答
void IIC_SendArk(bit Bit)
{
    I2C_SDA=Bit;
    I2C_SCL=1;
    I2C_SCL=0;
}

// 接受应答
bit IIC_ReciveArk(void)
{
    bit Bit;
    I2C_SDA=1; // 释放SDA，让从机操作
    I2C_SCL=1;
    Bit=I2C_SDA;
    I2C_SCL=0;
    return Bit;
}