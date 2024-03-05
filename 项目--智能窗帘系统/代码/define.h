#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <REGX52.H>
#include "intrins.h"

// LCD1602
sbit RW=P2^5;
sbit RS=P2^6;
sbit EN=P2^7;
sfr DATA=0x80; // P0

// DS18B20
sbit DQ=P3^7;

// BEEP
sbit BEEP=P2^4; // B5 ---> BEEP

// DS1302
sbit CE=P3^5;	// CE ---> RST
sbit SCLK=P3^6;	
sbit IO=P3^4;

// KEYS
sbit K1=P2^0;
sbit K2=P2^1;
sbit K3=P2^2;
sbit K4=P2^3;

// ADC0832 LIGHT
sbit CS=P1^5;
sbit CLK=P1^6;
sbit DI=P1^4;
sbit DO=P1^7;

// ULN2003A
sbit _1B=P1^0;
sbit _2B=P1^1;
sbit _3B=P1^2;
sbit _4B=P1^3;

#endif
