#include "MOTOR.h"


enum MOTOR_ENUM value;  // 拉起还是放下 最好保存在flash中

enum MOTOR_ENUM MOTOR_getValue(void)
{
	return value;
}

void MOTOR_setValue(enum MOTOR_ENUM set_value)
{
	value=set_value;
}


static void MOTOR_S(void)
{
	_1B=0;
	_2B=0;
	_3B=0;
	_4B=0;	
}

static void MOTOR_A(void)
{
	_1B=1;
	_2B=0;
	_3B=0;
	_4B=0;	
}

static void MOTOR_AB(void)
{
	_1B=1;
	_2B=1;
	_3B=0;
	_4B=0;	
}

static void MOTOR_B(void)
{
	_1B=0;
	_2B=1;
	_3B=0;
	_4B=0;	
}

static void MOTOR_BC(void)
{
	_1B=0;
	_2B=1;
	_3B=1;
	_4B=0;	
}

static void MOTOR_C(void)
{
	_1B=0;
	_2B=0;
	_3B=1;
	_4B=0;	
}

static void MOTOR_CD(void)
{
	_1B=0;
	_2B=0;
	_3B=1;
	_4B=1;	
}

static void MOTOR_D(void)
{
	_1B=0;
	_2B=0;
	_3B=0;
	_4B=1;	
}

static void MOTOR_DA(void)
{
	_1B=1;
	_2B=0;
	_3B=0;
	_4B=1;	
}

static void (*MOTOR_Action[9])(void);

void MOTOR_Init(void)
{
	MOTOR_getValue(); //  默认拉起	TODO 应从flash中读出
	
	MOTOR_Action[0]=MOTOR_A;
	MOTOR_Action[1]=MOTOR_AB;
	MOTOR_Action[2]=MOTOR_B;
	MOTOR_Action[3]=MOTOR_BC;
	MOTOR_Action[4]=MOTOR_C;
	MOTOR_Action[5]=MOTOR_CD;
	MOTOR_Action[6]=MOTOR_D;
	MOTOR_Action[7]=MOTOR_DA;
	MOTOR_Action[8]=MOTOR_S;
	
}

void MOTOR_Delay(void)
{
	unsigned int i=3,j;
	while(i--)
	{
		for(j=0; j<80; j++);
	}
}

void MOTOR_DownCasement(void) // 放下窗帘
{
	if(MOTOR_getValue()==MOTOR_Up)
	{
		unsigned char i,j;
		for(j=0;j<150;j++)
		{
			for(i=0;i<8;i++)
			{
				MOTOR_Action[8]();
				MOTOR_Action[i]();
				MOTOR_Delay();
			}
		}
		MOTOR_Action[8]();
		MOTOR_setValue(MOTOR_Down);
	}
}

void MOTOR_UpCasement(void)	// 拉起窗帘
{
	if(MOTOR_getValue()==MOTOR_Down)
	{
		unsigned char i,j; // 使用有符号的char时，出现停止i不停止问题
		for(j=0;j<150;j++)
		{
			for(i=0;i<8;i++)
			{
				MOTOR_Action[8]();
				MOTOR_Action[8-i-1]();
				MOTOR_Delay();
			}
		}
		MOTOR_Action[8]();
		MOTOR_setValue(MOTOR_Up);
	}
}

