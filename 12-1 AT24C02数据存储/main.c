#include <REGX52.H>
#include "intrins.h"
#include "key.h"
#include "LCD1602.h"
#include "Delay.h"
#include "AT24C02.h"

unsigned char keynum;
unsigned int num;

void main()
{
	LCD_Init();
    LCD_ShowNum(1,1,num,5);
	while(1)
	{
        keynum=key();
        if(keynum==1)
        {
            num++;
            LCD_ShowNum(1,1,num,5);
        }
        else if(keynum==2)
        {
            num--;
            LCD_ShowNum(1,1,num,5);
        }
        else if(keynum==3)
        {
            AT24C02_Write(0,num%256);
            DelayMs(5);
            AT24C02_Write(1,num/256);
            DelayMs(5);
            LCD_ShowNum(1,1,num,5);
            LCD_ShowString(2,1,"Write OK");
			DelayMs(1000);
			LCD_ShowString(2,1,"        ");
        }
        else if(keynum==4)
        {
            num=AT24C02_Read(0);
            num|=AT24C02_Read(1)<<8;
            LCD_ShowNum(1,1,num,5);
            LCD_ShowString(2,1,"Read OK ");
			DelayMs(1000);
			LCD_ShowString(2,1,"        ");
        }
	}
}