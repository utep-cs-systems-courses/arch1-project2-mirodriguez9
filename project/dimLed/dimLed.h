#ifndef dim_included
#define dim_included

#include <msp430.h>

#define BUTTON_0
#define LED_GREEN

extern unsigned char dim_on, dim_clock_on;

void initDimeClocks(); //Init clock
void initDim(); //Dim Green Led
int dimGreenLed(); //Dim Green Led

#endif
