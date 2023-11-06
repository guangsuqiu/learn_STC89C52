#include "buzzer.h"

static void Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}



void Buzzer_Time(unsigned int ms)
{
    unsigned int i;
    for(i=0;i<ms*2;i++)
    {
        BEEP=!BEEP;
        Delay500us();
    }
}
