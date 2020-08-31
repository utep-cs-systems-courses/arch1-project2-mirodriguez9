#include <msp430.h>
#include "libTimer.h"
#include "../dimLed/dimLed.h"

#define MODE_CLOCK  0x00

char mode_clock_frequency(char mode){
  char state = mode;

  switch(state){
  case0: //16Mhz
    configureClocks();
    enableWDTInterrupts();
    timerAUpmode();
    break;
  case1: //1Mhz
    WDTCL = WDTPW + WDTHOLD;//Stop
    BCSCTL1 = CALBC1_1MHZ;//Set DCO to 1 Mhz
    DCOCTL = CALDCO_1MHZ;
    BCSCTL2 &= ~(SELS);//SMCLK source = DCO
    break;
  }//end switch
  return mode;
}

char dim_mode_intensity(char power){
  char state = power;
  switch (state){
  case 0:
    __delay_cycles(200000);
    TA0CCR1 = 0;
    break;
  case 1:
     __delay_cycles(200000);
     TA0CCR1 =100;
     break;
  case 2:
     __delay_cycles(200000);
     TA0CCR1 = 200;
     break;
  case 3:
     __delay_cycles(200000);
     TA0CCR1 = 300;
     break;
  case 4:
     __delay_cycles(200000);
     TA0CCR1 = 400;
     break;
  case 5:
     __delay_cycles(200000);
     TA0CCR1 = 500;
     break;
  case 6:
     __delay_cycles(200000);
     TA0CCR1 = 600;
     break;
  case 7:
     __delay_cycles(200000);
     TA0CCR1 = 700;
     break;
}

  char mode_led(char mode){
    char state = mode;

    switch(state){
    case 0:
      configureClocks();
      enableWDTInterrupts();
      timerAUpmode();
      break;
      
    case 1:
      if(dim_on == 0){
	initDim();}
      break;
    }
    return mode;
  }
