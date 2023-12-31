#include <REGX52.H>
#include "DZP.h"
#include "Timer0.h"

unsigned char code date[]={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0x08,0x08,0x08,0xff,0x00,0x0e,0x15,
	0x15,0x15,0x08,0x00,0x7e,0x01,0x02,0x00,
	0x7e,0x01,0x02,0x00,0x0e,0x11,0x11,0x0e,
	0x00,0x7d,0x00,0x00,0x00,0x00,0x00,0x00,
	};
unsigned char offset;
void main()
{
	unsigned char i;
	MatrixLED_Init();
	Timer0Init();
	while(1)
	{
		for(i=0;i<8;i++)
		{
 			MatrixLED_ShowColumn(i,date[i+offset]);
		}
		
	}
}


void Timer0_Rountine(void)  interrupt 1
{
	static unsigned int i;
	i++;
    // 1. 计数器低八位
    TL0=64536%0x100;
    // 2. 计数器高八位
    TH0=64536/0x100;
	if(i>=300)
	{
		i=0;
		offset++;
		if(offset>sizeof(date)-8)
		{
			offset=0;
		}
	}
}