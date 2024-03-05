#include "DS18B20.h"
//#include "LCD1602.h"

void DS18B20_ConverT(void)
{
    OneWire_Init();
    OneWire_SendByte(0xCC);// 跳过rom
    OneWire_SendByte(0x44);// DS18B20开始模数转换
}


float DS18B20_ReadT (void)
{
    float ret;
    unsigned char TLSB,TMSB;
    int sum;
    OneWire_Init();
    OneWire_SendByte(0xCC);
    OneWire_SendByte(0xBE);
    TLSB=OneWire_ReceiveByte();
    TMSB=OneWire_ReceiveByte();
//    LCD_ShowBinNum(1,1,TMSB,8);
//    LCD_ShowBinNum(1,9,TLSB,8);
    sum=(TMSB<<8)|TLSB;
    ret=sum/16.0;
    return ret;
}