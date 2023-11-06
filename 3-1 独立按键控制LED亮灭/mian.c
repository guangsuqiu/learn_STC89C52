#include <REGX52.H>

void main()	
{
	while(1)
	{
		//按钮另一侧接地，如果按下按钮，引脚是低电平
		if(P3_1==0)//如果按下按钮则led点亮
			P2_0=0;
		else
			P2_0=1;
	}
}