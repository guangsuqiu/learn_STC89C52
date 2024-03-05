#include "BUZZER.h"

enum BUZZER_ENUM BUZZER_Value;

void BUZZER_Init(void)
{
	BEEP=0;
}

enum BUZZER_ENUM BUZZER_getValue(void)
{
	return BUZZER_Value;
}

void BUZZER_setValue(enum BUZZER_ENUM value)
{
	BUZZER_Value=value;
}

void BUZZER_Loop(void)
{
	if(BUZZER_Value==BUZZER_enable)
	{
		BEEP=!BEEP;
	}
	else
	{
		BEEP=0;
	}
}