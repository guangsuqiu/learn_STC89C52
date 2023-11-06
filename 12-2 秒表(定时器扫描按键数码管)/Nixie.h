#ifndef __NIXIE_H__
#define __NIXIE_H__

// 104问题 不能在头文件进行定义，否则会不能创建hex文件
// unsigned char NixieTable[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}
void Nixie_Loop(void);
void Nixie_Scan(unsigned char led,num);
void Nixie_SetBuf(unsigned char Location,Number);

#endif