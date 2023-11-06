#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <REGX52.H>
#include "intrins.h"
#include "Timer1.h"

sbit Motor=P1^0;

void Motor_Init(void);
void Motor_SetSpeed(unsigned char Speed);

#endif
