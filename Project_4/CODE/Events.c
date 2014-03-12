/** ###################################################################
**     Filename  : Events.C
**     Project   : Project_4
**     Processor : MC9S12XS128MAA
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-5-3, 23:12
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Event       :  AS1_OnIdle (module Events)
**
**     From bean   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when an idle condition on the
**         receiver is detected.
**         The event is available only when both <Interrupt
**         service/event> and <Receiver > properties are enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  AS1_OnIdle(void)
{
  if(AS1_GetCharsInRxBuf()>0){ 
    unsigned char cmd=255;
    AS1_RecvChar(&cmd);
    if(cmd==0){//handshake
      unsigned char t=0;
      unsigned char rply[2]={0};
      unsigned short x;
      //unsigned char r;
      x=AS1_RecvChar(&t);
      rply[1]=(t+17)&0xff;
      AS1_SendBlock(rply,2,&x);
    }else if(cmd==1){//general query
      word x;
      byte t[4];
      AS1_RecvBlock(t,4,&x);
      AS1_SendBlock((byte*)(t[0]+(t[1]<<8)),t[2]+(t[3]<<8),&x);
    }
  }
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
