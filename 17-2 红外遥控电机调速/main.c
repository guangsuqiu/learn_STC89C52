#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "Nixie.h"
#include "Motor.h"
#include "IR.h"

unsigned char Command,Speed;

void main()
{
	Motor_Init();
	IR_Init();
	while(1)
	{
		if(IR_GetDataFlag())
		{
			Command=IR_GetCommand();
			if(Command==IR_0) // 数字0
			{
				Speed=0;
			}
			if(Command==IR_1) // 数字1
			{
				Speed=1;
			}
			if(Command==IR_2) // 数字2
			{
				Speed=2;
			}
			if(Command==IR_3) // 数字3
			{
				Speed=3;
			}

			if(Speed==0)
			{
				Motor_SetSpeed(0);
			}
			if(Speed==1)
			{
				Motor_SetSpeed(50);
			}
			if(Speed==2)
			{
				Motor_SetSpeed(75);
			}
			if(Speed==3)
			{
				Motor_SetSpeed(100);
			}
		}
		Nixie(1,Speed);
	}
}

