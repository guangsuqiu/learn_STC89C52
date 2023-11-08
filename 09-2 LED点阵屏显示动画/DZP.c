#include "DZP.h"

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}

// 串行输出，并行输出
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1; // 发送数据
		SCK=0;
	}// 发送完毕
	RCK=1;  // 输出
	RCK=0;	// 清零
}

// Colunm 列
void MatrixLED_ShowColumn(unsigned char Colunm,Data)
{
	_74HC595_WriteByte(Data);
	P0=~(0x80>>Colunm);// 选择哪一列
	Delayus(500);
	P0=0xFF; // 段选位选清零
}