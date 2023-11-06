#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "LCD1602.h"
#include "ET2046.h"

unsigned int ADValue;

void main()
{
	LCD_Init();
	// 可调电阻，热敏电阻，光敏电阻
	LCD_ShowString(1,1,"ADJ  NTC  RG");
	while(1)
	{
		ADValue=ET2046_ReadAD(ET2046_XP_8);
		LCD_ShowNum(2,1,ADValue,3);
		ADValue=ET2046_ReadAD(ET2046_YP_8);
		LCD_ShowNum(2,6,ADValue,3);
		ADValue=ET2046_ReadAD(ET2046_VBAT_8);
		LCD_ShowNum(2,11,ADValue,3);
		DelayMs(100);
	}
}