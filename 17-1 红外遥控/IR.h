#ifndef __IR_H__
#define __IR_H__

#include <REGX52.H>
#include "intrins.h"
#include "INT0.h"
#include "Timer0.h"

void IR_Init(void);
unsigned char IR_GetDataFlag(void);
unsigned char IR_GetRepeatFlag(void);
unsigned char IR_GetAddress(void);
unsigned char IR_GetCommand(void);

#endif
