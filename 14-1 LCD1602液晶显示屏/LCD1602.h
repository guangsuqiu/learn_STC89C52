#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <REGX52.H>
#include "intrins.h"

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

#define LCD_DataPort P0

void LCD_WriteCommand(unsigned char Command);
void LCD_WriteData(unsigned char Data);
void LCD_Init(void);
void LCD_ShowChar(unsigned char Line,unsigned char Conlumn,unsigned char Char);
void LCD_ShowString(unsigned char Line,unsigned char Conlumn,unsigned char *string);
void LCD_ShowNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Conlumn,signed int num,unsigned char len);
void LCD_ShowHexNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len);
void LCD_ShowBinNum(unsigned char Line,unsigned char Conlumn,unsigned int num,unsigned char len);
#endif