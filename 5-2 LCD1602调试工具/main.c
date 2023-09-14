#include "LCD1602.h"

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"hello world!");
	LCD_ShowNum(2,1,20,2);
	LCD_ShowSignedNum(2,3,-66,2);
	LCD_ShowHexNum(2,7,0x12,2);
	LCD_ShowBinNum(2,10,3,5);
	while(1)
	{
		LCD_Init();
		LCD_ShowString(1,1,"2023-03-23 22:57:06");
	}
}