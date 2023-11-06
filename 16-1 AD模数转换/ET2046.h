#ifndef __ET2046_H__
#define __ET2046_H__

#include <REGX52.H>
#include "intrins.h"

#define ET2046_XP_8 0x9C
#define ET2046_YP_8 0xDC
#define ET2046_VBAT_8 0xAC
#define ET2046_AUX_8 0xEC

#define ET2046_XP_12 0x94
#define ET2046_YP_12 0xD4
#define ET2046_VBAT_12 0xA4
#define ET2046_AUX_12 0xE4

sbit ET2046_CS=P3^5;
sbit ET2046_DCLK=P3^6;
sbit ET2046_DIN=P3^4;
sbit ET2046_DOUT=P3^7;

unsigned int ET2046_ReadAD(unsigned char Command);

#endif
