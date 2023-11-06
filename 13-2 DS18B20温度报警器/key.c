
#include "key.h"
#include <REGX52.H>

unsigned char Key_KeyNumber;

unsigned char Key(void)
{
    // 如果没有按键按下，会返回上次的结果，所以要清零一下
    unsigned char temp=Key_KeyNumber;
    Key_KeyNumber=0; 
    return temp;
}


unsigned char Key_GetState(void)
{
	unsigned char KeyNumber=0;
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	return KeyNumber;
}

void Key_Loop(void)
{
    static unsigned char NowState,LastState;
    LastState=NowState;
    NowState=Key_GetState();
    if(LastState==1&&NowState==0) // 按键1松开的时候
    {
        Key_KeyNumber=1;
    }
    if(LastState==2&&NowState==0) // 按键2松开的时候
    {
        Key_KeyNumber=2;
    }
    if(LastState==3&&NowState==0) // 按键3松开的时候
    {
        Key_KeyNumber=3;
    }
    if(LastState==4&&NowState==0) // 按键4松开的时候
    {
        Key_KeyNumber=4;
    }
}