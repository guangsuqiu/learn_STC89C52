/***
 * @Author       : guangsuqiu guangsuqiu@gmail.com
 * @Date         : 2023-11-04 19:36:14
 * @LastEditTime : 2023-11-07 00:18:19
 * @FilePath     : \learn_STC89C52\9-1 LED点阵屏显示图形\main.c
 * @Description  : 
 * @Copyright (c) 2023 by guangsuqiu , All Rights Reserved. 
 * @
 */

#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;	// PCLK
sbit SCK=P3^6;	// SRCLK
sbit SER=P3^4;	// SER

// 串行输出，并行输出
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	RCK=0;
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

void main()
{
	// 笑脸代码
	while(1)
	{
		MatrixLED_ShowColumn(0,0x3c);
		MatrixLED_ShowColumn(1,0x42);
		MatrixLED_ShowColumn(2,0xa9);
		MatrixLED_ShowColumn(3,0x85);
		MatrixLED_ShowColumn(4,0x85);
		MatrixLED_ShowColumn(5,0xa9);
		MatrixLED_ShowColumn(6,0x42);
		MatrixLED_ShowColumn(7,0x3c);
	}
}