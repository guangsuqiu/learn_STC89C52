#include <REGX52.H>
#include "intrins.h"
#include "key.h"
#include "Nixie.h"
#include "buzzer.h"

void main()
{
	unsigned char keyNum=0;
    
	while(1)
	{
        keyNum=key();
        if(keyNum)
        {
            Buzzer_Time(100);
            Nixie(1,keyNum);
        }
	}
}