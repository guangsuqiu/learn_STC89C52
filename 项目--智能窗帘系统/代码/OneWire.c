#include "OneWire.h"


unsigned char OneWire_Init(void)
{
    unsigned char i,ack;
	EA=0;
	
    DQ=1;
    DQ=0;
    // delay 500us
	i = 227;
	while (--i);
    DQ=1;
    // delay 70us
	i = 29;
	while (--i);
    ack=DQ;
    // delay 500us
    i = 227;
	while (--i);
	
	// 中断导致度数出现问题
	EA=1;
    return ack;
}

void OneWire_SendBit(unsigned char Bit)
{
    unsigned char i;
	EA=0;
	
    DQ=0;
    // 10us
	_nop_();
	i = 3;
	while (--i);
    DQ=Bit;
    // 50us
    i = 22;     
	while (--i);
    DQ=1;
	
	EA=1;
}


unsigned char OneWire_ReceiveBit(void)
{
    unsigned char Bit,i;
	EA=0;
	
    DQ=0;
    // 5us
    i = 1;
	while (--i);
    DQ=1;
    // 5us
    i = 1;
	while (--i);
    Bit=DQ;
    // 50us
    i = 22;     
	while (--i);
	
	EA=1;
    return Bit;
}


void OneWire_SendByte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(Byte&(0x01<<i));        
    }   
}


unsigned char OneWire_ReceiveByte(void)
{
    unsigned char i;
    unsigned char Byte=0x00;
    for(i=0;i<8;i++)
    {
        if(OneWire_ReceiveBit()==1)
        {
            Byte|=(0x01<<i);
        }        
    }   
    return Byte;
}