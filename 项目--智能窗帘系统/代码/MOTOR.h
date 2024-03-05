#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "define.h"

/*
	如果想确定步进电机理想与实际的位置是否相同，可以通过增加一个编码器来检测
*/

enum MOTOR_ENUM
{
	MOTOR_Up, 	// 拉起
	MOTOR_Down	// 放下
};

enum MOTOR_ENUM MOTOR_getValue(void);
void MOTOR_setValue(enum MOTOR_ENUM set_value);
void MOTOR_Init(void);
void MOTOR_DownCasement(void);	//	+180	放下窗帘
void MOTOR_UpCasement(void);	// 	-180	拉起窗帘

#endif
