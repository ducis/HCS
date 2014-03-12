/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : EC161.C
**     Project   : ProjectPulseCapture
**     Processor : MC9S12XS128MAL
**     Beantype  : EventCntr16
**     Version   : Bean 02.132, Driver 01.15, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 11:25
**     Abstract  :
**         This bean "EventCntr16" implements an 16-bit event counter.
**         It counts the external events (specified edges of the external
**         signal). It uses a hardware timer counter.
**         The counter width is extended or taperred to 16 bits.
**     Settings  :
**         Timer name                  : PACNT [16-bit]
**
**         Counting mode               : Simple counter
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       18            |  PT7_IOC7_PWM7
**             ----------------------------------------------------
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**         Counter register            : PACNT     [98]
**         Mode register               : PACTL     [96]
**         Run register                : PACTL     [96]
**     Contents  :
**         Reset        - byte EC161_Reset(void);
**         GetNumEvents - byte EC161_GetNumEvents(word *Value);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE EC161. */

#include "EC161.h"


#pragma DATA_SEG EC161_DATA
#pragma CODE_SEG EC161_CODE


/*
** ===================================================================
**     Method      :  EC161_Reset (bean EventCntr16)
**
**     Description :
**         This method resets the external event counter (sets it to
**         zero).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
** ===================================================================
*/
byte EC161_Reset(void)
{
  EnterCritical();                     /* Save the CCR register */
  /* PACNT: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(PACNT, 0);                  /* Reset the counter */ 
  /* PAFLG: ??=0,??=0,??=0,??=0,??=0,??=0,PAOVF=1,PAIF=0 */
  setReg8(PAFLG, 2);                   /* Reset the overflow flag */ 
  ExitCritical();                      /* Restore the CCR register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  EC161_GetNumEvents (bean EventCntr16)
**
**     Description :
**         This method returns the number of the external events.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the returned number of
**                           the external events
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_OVERFLOW - Timer overflow
** ===================================================================
*/
byte EC161_GetNumEvents(word *Value)
{
  *Value = PACNT;                      /* Load of actual value of the counter register */
  if (PAFLG & 2) {                     /* Is overflow error */
    return ERR_OVERFLOW;               /* Error */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  EC161_Init (bean EventCntr16)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void EC161_Init(void)
{
  /* PACNT: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(PACNT, 0);                  /* Reset Counter */ 
  /* PAFLG: ??=0,??=0,??=0,??=0,??=0,??=0,PAOVF=1,PAIF=0 */
  setReg8(PAFLG, 2);                   /* Reset request flag */ 
  /* PACTL: ??=0,PAEN=1,PAMOD=0,PEDGE=1,CLK1=0,CLK0=0,PAOVI=0,PAI=0 */
  setReg8(PACTL, 80);                  /* Set up pulse accumulator mode */ 
}

/* END EC161. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/