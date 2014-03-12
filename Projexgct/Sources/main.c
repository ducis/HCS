#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */






void main(void) {
  /* put your own code here */
  DDRB=0xFF;
  PORTB=0;
  DDRT=0x00;
	//EnableInterrupts;

  //TIOS_IOS3=0;
  for(;;) {
    if(PTT_PTT2){
      PORTB_PB1=1;
    }else{
      PORTB_PB2=1;
    }
    PORTB_PB0=1;
    //PORTB_PB0=PTT_PTT3;
    //if(OC7D_OC7D3){
    //   PORTB_PB0=1;
    //}
    //if(TC3H){
    //   PORTB_PB0=1;
    //}
    //if(TC3L){
    //   PORTB_PB0=1;
    //}
    //if(TC3){
    //   PORTB_PB0=1;
    //}
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
