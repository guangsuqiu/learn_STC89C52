#include <STC89C5xRC.H>

void mian()	
{
	while(1)
	{
		//按钮另一侧接地，如果按下按钮，引脚是低电平
		if(P31==0)//如果按下按钮则led点亮
			P20=0;
		else
			P20=1;
	}
}