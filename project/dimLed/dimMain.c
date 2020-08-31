#include <msp430.h>
#include "libTimer.h"
#include "dimLed.h"

//Run dim led
int main(){
  initDimClocks();
  dimGreenLed(); //dim!
}
