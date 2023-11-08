

#include "MatrixKey.h"

unsigned char MatrixKey(void)
{
    unsigned char KeyNumber=0;
    // 扫描第一列
    P1=0xFF; // 将矩阵键盘的八个引脚分别置为高电平
    P1_3=0; // 将第一列的引脚置为0
    if(P1_7==0)  //S1
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_7==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=1;
    }
    if(P1_6==0)  //S5
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_6==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=5;
    }
    if(P1_5==0)  //S9
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_5==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=9;
    }
    if(P1_4==0)  //S13
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_4==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=13;
    }

    // 扫描第二列
    P1=0xFF; // 将矩阵键盘的八个引脚分别置为高电平
    P1_2=0; // 将第二列的引脚置为0
    if(P1_7==0)  //S2
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_7==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=2;
    }
    if(P1_6==0)  //S6
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_6==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=6;
    }
    if(P1_5==0)  //S10
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_5==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=10;
    }
    if(P1_4==0)  //S14
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_4==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=14;
    }

    // 扫描第三列
    P1=0xFF; // 将矩阵键盘的八个引脚分别置为高电平
    P1_1=0; // 将第三列的引脚置为0
    if(P1_7==0)  //S3
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_7==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=3;
    }
    if(P1_6==0)  //S7
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_6==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=7;
    }
    if(P1_5==0)  //S11
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_5==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=11;
    }
    if(P1_4==0)  //S15
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_4==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=15;
    }

    // 扫描第四列
    P1=0xFF; // 将矩阵键盘的八个引脚分别置为高电平
    P1_0=0; // 将第四列的引脚置为0
    if(P1_7==0)  //S4
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_7==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=4;
    }
    if(P1_6==0)  //S8
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_6==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=8;
    }
    if(P1_5==0)  //S12
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_5==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=12;
    }
    if(P1_4==0)  //S16
    {
        DelayMs(20); // 消除按下的抖动
        while (P1_4==0); // 等待松开
        DelayMs(20); // 消除松开的抖动
        KeyNumber=16;
    }

    return KeyNumber;
}