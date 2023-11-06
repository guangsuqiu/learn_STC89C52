#include "OneWire.h"


unsigned char OneWire_Init(void)
{
    unsigned char i,ack;
    OneWire_DQ=1;
    OneWire_DQ=0;
    // delay 500us
	i = 227;
	while (--i);
    OneWire_DQ=1;
    // delay 70us
	i = 29;
	while (--i);
    ack=OneWire_DQ;
    // delay 500us
    i = 227;
	while (--i);
    return ack;
}

void OneWire_SendBit(unsigned char Bit)
{
    unsigned char i;
    OneWire_DQ=0;
    // 10us
	_nop_();
	i = 3;
	while (--i);
    OneWire_DQ=Bit;
    // 50us
    i = 22;     
	while (--i);
    OneWire_DQ=1;
}


unsigned char OneWire_ReceiveBit(void)
{
    unsigned char Bit,i;
    OneWire_DQ=0;
    // 5us
    i = 1;
	while (--i);
    OneWire_DQ=1;
    // 5us
    i = 1;
	while (--i);
    Bit=OneWire_DQ;
    // 50us
    i = 22;     
	while (--i);
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