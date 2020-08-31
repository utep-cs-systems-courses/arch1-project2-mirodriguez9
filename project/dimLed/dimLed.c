#include <msp430.h>
#include "dimLed.h"
#define BUT0  BIT3
#define GREEN BIT6

unsigned char dim_on, dim_clock_on =0;

void initDime(){
  P1DIR |= GREEN; //set green to be on by default
  P1REN |= BUT0; //enable resistor for button 0
  P1OUT |= BUT0;
  P1SEL |= GREEN;//select port for green led

  TA0CCR0 = 1000-1; //Set the timer, the bigger the more steps
  TA0CCTL1 = OUTMOD_7;
  TA0CCR1 = 0;      //The PWM period to 0
  TA0CTL = TASSEL_2 + MC_1; // Clock source, Mode1

  dim_on = 1;
}

int dimGreenLed(){
  __delay_cycles(200000);
  TA0CCR = TA0CCR1 + 200; //Increment the PWM (dim) period

  if (TA0CCR1 > 1000-1){
    TA0CCR1 = 0; // Reset TACCR1
  }
  return 0;
}//end dimGreenLed

/*Clocks have to be samll so that we can notice the interrupts, if we use 16 Mhz it will give an error*/
void initDimClocks(){
  WDTCL = WDTPW + WDTHOLD; //stop
  BCSCTL1 = CALBC1_1MHZ; //set DCO to 1 Mhz
  DCOCTL = CALDCO_1MHZ;

  BCSCTL2 &= ~(SELS); //SMCLK source DCO

  dim_clock = 1;
}
