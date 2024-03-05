#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "define.h"

enum BUZZER_ENUM
{
	BUZZER_disable,
	BUZZER_enable
};

void BUZZER_Init(void);
enum BUZZER_ENUM BUZZER_getValue(void);
void BUZZER_Loop(void);
void BUZZER_setValue(enum BUZZER_ENUM value);

#endif
