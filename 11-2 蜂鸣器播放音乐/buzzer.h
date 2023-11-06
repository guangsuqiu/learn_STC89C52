#ifndef __BUZZER_H__
#define __BUZZER_H__

#include <REGX52.H>
#include "intrins.h"

sbit BEEP=P2^5;

void Buzzer_Time(unsigned int ms);

#endif