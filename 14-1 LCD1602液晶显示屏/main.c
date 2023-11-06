#include "LCD1602.h"
#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"

void main()
{
	int num=-32768;
	LCD_Init();
    LCD_ShowChar(1,1,'A');
    LCD_ShowString(1,3,"ABC");
	LCD_ShowNum(1,7,255,3);
	LCD_ShowSignedNum(1,11,num,5);
	LCD_ShowHexNum(2,1,0xA5,2);
	LCD_ShowBinNum(2,4,0xA5,8);
	LCD_ShowChar(2,13,0xdf);
	LCD_ShowChar(2,14,'C');
	LCD_ShowString(1,16,"Welcome to China!");
	while(1)
	{
        LCD_WriteCommand(0x18);
		DelayMs(1000);
	}
}