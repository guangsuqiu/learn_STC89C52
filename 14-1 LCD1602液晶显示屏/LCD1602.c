#include "LCD1602.h"

void LCD_Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
    LCD_RS=0;
    LCD_RW=0;
    LCD_DataPort=Command;
    LCD_E=1;
    LCD_Delay1ms();
    LCD_E=0;
    LCD_Delay1ms();
}

void LCD_WriteData(unsigned char Data)
{
    LCD_RS=1;
    LCD_RW=0;
    LCD_DataPort=Data;
    LCD_E=1;
    LCD_Delay1ms();
    LCD_E=0;
    LCD_Delay1ms();
}


unsigned char pow(unsigned X,Y)
{
	unsigned ret=1,i;
	for(i=1;i<Y;i++)
	{
		ret=ret*X;
	}
	return ret;
}


void LCD_Init(void)
{
    LCD_WriteCommand(0x38); // 设置模式
    LCD_WriteCommand(0x0c);
    LCD_WriteCommand(0x06);
    LCD_WriteCommand(0x01);
}

void LCD_ShowChar(unsigned char Line,unsigned char Conlumn,unsigned char Char)
{
    if(Line==1)
    {
        LCD_WriteCommand(0x80|(Conlumn-1));
    }
    else if (Line ==2)
    {
        LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
    }
    LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Conlumn,unsigned char *string)
{
    unsigned char i;
    if(Line==1)
    {
        LCD_WriteCommand(0x80|(Conlumn-1));
    }
    else if (Line ==2)
    {
        LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
    }
    for(i=0;string[i]!='\0';i++)
    {
        LCD_WriteData(string[i]);
    }
}

void LCD_ShowNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len)
{
   unsigned int chu=1;
   unsigned char i;
   if(Line==1)
   {
       LCD_WriteCommand(0x80|(Conlumn-1));
   }
   else if (Line ==2)
   {
       LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
   }
    // 获取第一次的除数
    for(i=1;i<len;i++)
    {
        chu=chu*10;
    }
    for(i=0;i<len;i++)
    {
        LCD_WriteData(num/chu%10+'0');
        chu=chu/10;       
    }
}

void LCD_ShowSignedNum(unsigned char Line,unsigned char Conlumn,signed int num,unsigned char len)
{
   unsigned int chu=1,num1;
   unsigned char i;
   if(Line==1)
   {
       LCD_WriteCommand(0x80|(Conlumn-1));
   }
   else if (Line ==2)
   {
       LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
   }
   if(num<0)
   {
        LCD_WriteData('-');
        num1=-num;
   }
   else if(num>0)
   {
        LCD_WriteData('+');
	   num1=num;
   }
    // 获取第一次的除数
    for(i=1;i<len;i++)
    {
        chu=chu*10;
    }
    for(i=0;i<len;i++)
    {
        LCD_WriteData(num1/chu%10+'0');
        chu=chu/10;       
    }
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len)
{
	unsigned char i,temp;
    if(Line==1)
    {
        LCD_WriteCommand(0x80|(Conlumn-1));
    }
    else if (Line ==2)
    {
        LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
    }
	for(i=len;i>0;i--)
	{
		temp=num/pow(16,i)%16;
		if(temp<10)
		{
			LCD_WriteData(temp+'0');
		}
		else
		{
			LCD_WriteData(temp+'A'-10);
		}
	}
}


void LCD_ShowBinNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len)
{
	unsigned char i,temp;
    if(Line==1)
    {
        LCD_WriteCommand(0x80|(Conlumn-1));
    }
    else if (Line ==2)
    {
        LCD_WriteCommand(0x80|(Conlumn-1)+0x40);
    }
	for(i=len;i>0;i--)
	{
		temp=num/pow(2,i)%2;
		if(temp<10)
		{
			LCD_WriteData(temp+'0');
		}
		else
		{
			LCD_WriteData(temp+'A'-10);
		}
	}
}