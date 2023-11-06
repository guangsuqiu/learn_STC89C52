#include "ET2046.h"

unsigned int ET2046_ReadAD(unsigned char Command)
{
	// 必须清零，否则数据错
	unsigned int ADValue=0;
	unsigned char i;
	ET2046_DCLK=0;
	ET2046_CS=0;
	
	for(i=0;i<8;i++)
	{
		ET2046_DIN=Command&(0x80>>i);
		ET2046_DCLK=1;
		ET2046_DCLK=0;
	}
	for(i=0;i<16;i++)
	{
		ET2046_DCLK=1;
		ET2046_DCLK=0;
		if(ET2046_DOUT)
		{
			ADValue|=(0x8000>>i);
		}
	}
	ET2046_CS=1;
	if(Command&0x08)
		return ADValue>>8;
	else
		return ADValue>>4;
}