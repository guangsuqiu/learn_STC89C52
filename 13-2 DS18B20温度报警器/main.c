#include <REGX52.H>
#include "intrins.h"
#include "DS18B20.h"
#include "LCD1602.h"
#include "key.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Timer0.h"

float T,Tshow;
char TLow,THigh;
unsigned char keynum;

void main()
{
    DS18B20_ConverT();
    THigh=AT24C02_Read(0);	//读取温度阈值数据
	TLow=AT24C02_Read(1);
	if(THigh>125 || TLow<-55 || THigh<=TLow)
	{
		THigh=20;			//如果阈值非法，则设为默认值
		TLow=15;
	}
	LCD_Init();
    LCD_ShowString(1,1,"T:");
    LCD_ShowString(2,1,"TH:");
    LCD_ShowString(2,9,"TL:");
    LCD_ShowSignedNum(2,4,THigh,3);
    LCD_ShowSignedNum(2,12,TLow,3);
    
    Timer0_Init();
	while(1)
	{
        keynum=Key();
        
        // 温度读取及显示
        DS18B20_ConverT();
        T=DS18B20_ReadT();
        if(T<0)
        {
            LCD_ShowChar(1,3,'-');
            Tshow=-T;
        }
        else
        {   
            LCD_ShowChar(1,3,'+');
            Tshow=T;
        }
        LCD_ShowNum(1,4,Tshow,3);
        LCD_ShowChar(1,7,'.');
        LCD_ShowNum(1,8,(unsigned long)(Tshow*100)%100,2);
        
        // 阈值判断及显示
        if(keynum)
        {   
            if(keynum==1)
            {
                THigh++;
                if(THigh>=125)
                {
                    THigh=125;
                }
            }
            if(keynum==2)
            {
                THigh--;
                if(THigh <=TLow)
                {
                    THigh++;
                }
            }
            if(keynum==3)
            {
                TLow++;
                if(THigh <=TLow)
                {
                    TLow--;
                }
            }
            if(keynum==4)
            {
                TLow--;
                if(TLow<-55)
                {
                    TLow=-55;
                }
            }
            LCD_ShowSignedNum(2,4,THigh,3);
            LCD_ShowSignedNum(2,12,TLow,3);
            AT24C02_Write(0,THigh);		//写入到At24C02中保存
			DelayMs(5);
			AT24C02_Write(1,TLow);
			DelayMs(5);
        } 
        if(T>THigh)
        {
            LCD_ShowString(1,13,"OV:H");
        }
        else if(T<TLow)
        {
            LCD_ShowString(1,13,"OV:L");
        }
        else
        {
            LCD_ShowString(1,13,"    ");
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
	if(i>=20)
	{
		Key_Loop();
        i=0;
	}
}


