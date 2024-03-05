#include "Delay.h"
#include "DS1302.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "ADC0832.h"
#include "BUZZER.h" 	
#include "KEY.h"
#include "BULETOOTH.h"	
#include "MOTOR.h"

void Timer0_Init(void);

unsigned char rec;
static unsigned char KeyNum;


void main()
{
	BUZZER_Init();
	Timer0_Init();
	LCD_Init();
	DS1302_Init();
	HC08_Init();
	MOTOR_Init();
	
	DS18B20_ConverT();
	LCD_ShowString(1,1,"  -  -     :    ");//静态字符初始化显示

	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)	
		{
			MOTOR_DownCasement();
		}
		else if(KeyNum==2)	
		{
			MOTOR_UpCasement();
		}
		else if(KeyNum==3)	
		{
			BUZZER_setValue(BUZZER_enable);
		}
		else if(KeyNum==4)
		{
			BUZZER_setValue(BUZZER_disable);
		}
		else
		{
			DS18B20_ConverT();
			
			//  时钟
			DS1302_ReadTime();//读取时间
			LCD_ShowNum(1,1,DS1302_Time[0],2);//显示年
			LCD_ShowNum(1,4,DS1302_Time[1],2);//显示月
			LCD_ShowNum(1,7,DS1302_Time[2],2);//显示日
			LCD_ShowNum(1,10,DS1302_Time[3],2);//显示时
			LCD_ShowNum(1,13,DS1302_Time[4],2);//显示分
			
			//  光照
			LCD_ShowNum(2,1,ADC0832_getLight(),2);
			
			//  温度
			LCD_ShowSignedNum(2,4,(int)DS18B20_ReadT(),2);
			
			//  电机状态
			if(MOTOR_getValue()==MOTOR_Up)
			{
				LCD_ShowString(2,8,"U  P");
			}
			else
			{
				LCD_ShowString(2,8,"DOWN");
			}
			
			//  蜂鸣器状态
			if(BUZZER_getValue()==BUZZER_disable)
			{
				LCD_ShowString(2,13,"OFF");
			}
			else
			{
				LCD_ShowString(2,13,"O N");
			}
			
			DelayMs(500);
		}
	}
}

/**
  * @brief  定时器0初始化，1毫秒@12.000MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init(void)
{
	// 选择Timer0 为模式1
    TMOD&=0xf0;
    TMOD|=0x01;
    // 初始化中断溢出标志位 溢出时自动设为1 等待中断响应后自动设为0
    TF0=0;
    // 初始化计数器数据
    // 1. 计数器低八位
    TL0=64536%0x100;
    // 2. 计数器高八位
    TH0=64536/0x100;
    // 开始计时
    TR0=1;
    // 开启中断
    ET0=1;
    // 开启总中断开关
    EA=1;
    // 选择中断优先级为低优先级
    PT0=0;
}


void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		Key_Loop();	//20ms调用一次按键驱动函数
	}
	T0Count2++;
	if(T0Count2>=500)
	{
		T0Count2=0;
		BUZZER_Loop();//500ms调用一次蜂鸣器驱动函数
	}
}

// TODO 串口通信需要协议
void UART_Routime(void) interrupt 4
{
	if(RI==1)
	{
		rec=SBUF;
		RI=0;
	}
}

// TODO 按键菜单
void KEY_Menu(void)
{
	// 清屏
	LCD_ShowString(1,1,"                ");
	LCD_ShowString(2,1,"                ");
	// 显示菜单
	LCD_ShowString(1,1,"WelcomeCurtainOS");
	while(1)
	{	
		KeyNum=Key();
		if(KeyNum==2) // 菜单下移
		{
			
		}
		else if(KeyNum==3) // 菜单上移
		{
			
		}
		else if(KeyNum==4) // 进去子菜单
		{
			
		}
		else if(KeyNum==1) // 退出菜单
		{
			break;
		}
		else
		{
			
		}
	}
}




