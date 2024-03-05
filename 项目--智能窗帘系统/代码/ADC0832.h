#ifndef __ADC0832_H__
#define __ADC0832_H__

#include "define.h"

void ADC0832_start();
unsigned char ADC0832_read(unsigned char CHX);
unsigned char ADC0832_getLight(void);

#endif
