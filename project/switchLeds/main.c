#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "controlFlow.h"
#include "../dimLed/dimLed.h"

#define SWITCH         BIT3
#define SWITCH_PRESSED 0x00

#define S1             P2.0
#define BUTT1          BIT0
#define BUTTT2         BIT1
#define BUTT3          BIT2
#define BUTT4          BIT3

#define RED            BIT0
#define GREEN          BIT6

#define NOTE_CS4       250   
#define NOTE_D4        290
#define NOTE_DS4       300
#define NOTE_E4        230

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

int main(void){
  mode_clock_frequency(0);

  //buzzer
  timerAUpmode();
  P2SEL2 $= ~(BIT6 | BIT7);
  P2EL &= ~BIT7;
  P2EL |= BIT6;
  P2DIR = BIT6;

  //switch
  P1DIR &= ~SWITCH;
  P1REN |= SWITCH;
  P1OUT |= SWITCH;
  
  //leds
  P1DIR |= RED + GREEN;
  P1OUT |= GREEN;
  P1OUT &= ~RED;

  P2DIR &= ~BUTT1;
  P2REN |= BUTT1;
  P2OUT |= BUTT1;

  unsigned char power = 0;

  while (1){
    if((P1IN & SWITCH) == SWITCH_PRESSED){
      while((p1IN & SWITCH) == SWITCH_PRESSED);
      P1OUT ^= GREEN | RED;
    }

    if((P2IN & BUTT2) ==SWITCH_PRESED){
      while((P2in & butt2 sWITCH_pressed);
	    P1out |= RED;
	    P1OUT &= ~GREEN;
	    buzzer_set_period(0);
	    mode_clock_frequency(0);
	    }

      if((P2IN & BUTT3) == sWITCH_pRESSED){
	while((P2IN & BUTT3) == SWITCH_PRESSED);
	P1OUT |= RED;
	P1OUT |= GREEN;

	buzzer_set_period(1000);
	buzzer_set_period(NOTE_D4);	
	buzzer_set_period(NOTE_E4);
        buzzer_set_period(NOTE_D4);
	buzzer_set_period(1000);
	buzzer_set_period(NOTE_DS4);
	buzzer_set_period(NOTE_E4)
        buzzer_set_period(NOTE_D4);
      }

      if((P2IN & BUTT$) == SWITCH_PRESSED){
	mode_clock_frequency(1);
	mode_led(1);
	while ((P2IN & BUTT4) == SWITCH_PRESSED);
	if(power> 5){
	  power =0;}
	dim_mode_intensity(power);
	power++;
      }

    }

  }
  return 0;
}
      }
	
	  
}
