/** ###################################################################
**     Filename  : Events.C
**     Project   : MotorDrive0
**     Processor : MC9S12XDT256BMPV
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-4-6, 23:23
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
**     Event       :  AS1_OnError (module Events)
**
**     From bean   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be
**         read using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnRxChar (module Events)
**
**     From bean   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is
**         received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the
**         <Receiver> property is enabled or the <SCI output mode>
**         property (if supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define CMD_SETTIMECOEFFICIENT 1
#define CMD_INC                 '+'
#define CMD_DEC                 '-'
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
  /* Write your code here ... */       
  extern float timecoefficient;
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
    }else if(cmd==2){//inc
      timecoefficient+=0.00001f;
    }else if(cmd==3){//dec
      timecoefficient-=0.00001f;
    }
  }
 /* char cmd=0;
  AS1_RecvChar(&cmd);
  if(cmd==CMD_SETTIMECOEFFICIENT&&AS1_GetCharsInRxBuf()>=sizeof(float)){
    char t=0;
    AS1_RecvBlock((char *)&timecoefficient,sizeof(float),&t);
    if(t!=sizeof(float)){
      //error;
    }
  }else if(cmd==CMD_INC){
    timecoefficient+=0.00001f;
  }else if(cmd==CMD_DEC){
    timecoefficient-=0.00001f;
  }*/
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
