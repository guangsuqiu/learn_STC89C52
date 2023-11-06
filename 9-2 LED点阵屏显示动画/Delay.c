
#include "Delay.h"

void Delayus(unsigned int us)		//@11.0592MHz
{
	while(us--)
	{
		_nop_();
	}
}
