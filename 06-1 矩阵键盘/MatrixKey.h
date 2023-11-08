

#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__

#include <REGX52.H>
#include "Delay.h"

/**
 * @brief 扫描矩阵键盘哪个按键被按下
 * 
 * @return unsigned char  返回按键按下对应的值，没按下返回0
 */
unsigned char MatrixKey(void);

#endif  // __MATRIXKEY_H__