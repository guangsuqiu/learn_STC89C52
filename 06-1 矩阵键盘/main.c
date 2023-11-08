
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char MatrixKeyNum;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:");
	while (1)
	{
		MatrixKeyNum=MatrixKey();
		if(MatrixKeyNum)
		{
			LCD_ShowNum(2,1,MatrixKeyNum,2);
		}
	}
}