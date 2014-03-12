/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PWM8.C
**     Project   : Project
**     Processor : MC9S12XS128MAL
**     Beantype  : PWM
**     Version   : Bean 02.207, Driver 01.14, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 16:11
**     Abstract  :
**         This bean implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       4             |  PP0_KWP0_PWM0_IOC0_RxD1
**             ----------------------------------------------------
**
**         Timer name                  : PWM0 [8-bit]
**         Counter                     : PWMCNT0   [780]
**         Mode register               : PWMCTL    [773]
**         Run register                : PWME      [768]
**         Prescaler                   : PWMPRCLK  [771]
**         Compare 1 register          : PWMPER0   [788]
**         Compare 2 register          : PWMDTY0   [796]
**         Flip-flop 1 register        : PWMPOL    [769]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : P
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**         Port data register          : PTP       [600]
**         Port control register       : DDRP      [602]
**
**         Runtime setting period      : none
**         Runtime setting ratio       : calculated
**         Initialization:
**              Aligned                : Left
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 500 Hz
**           Initial value of            period        pulse width (ratio 20%)
**             Xtal ticks              : 8000000       1600000
**             microseconds            : 500000        100000
**             milliseconds            : 500           100
**             seconds (real)          : 0.5000000     0.1000000
**
**     Contents  :
**         Enable     - byte PWM8_Enable(void);
**         Disable    - byte PWM8_Disable(void);
**         SetRatio16 - byte PWM8_SetRatio16(word Ratio);
**         SetDutyUS  - byte PWM8_SetDutyUS(word Time);
**         SetDutyMS  - byte PWM8_SetDutyMS(word Time);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/


/* MODULE PWM8. */

#include "PWM8.h"

#pragma DATA_SEG PWM8_DATA
#pragma CODE_SEG PWM8_CODE

static bool EnUser;                    /* Enable/Disable device by user */
static word RatioStore;                /* Ratio of L-level to H-level */


/*
** ===================================================================
**     Method      :  HWEnDi (bean PWM)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of the Enable and 
**         Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  if (EnUser) {                        /* Enable device? */
    PWME_PWME0 = 1;                    /* Run counter */
  } else {                             /* Disable device? */
    PWME_PWME0 = 0;                    /* Stop counter */
    PWMCNT0 = 0;                       /* Reset counter */
  }
}

/*
** ===================================================================
**     Method      :  SetRatio (bean PWM)
**
**     Description :
**         The method reconfigures the compare and modulo registers of 
**         the peripheral(s) when the speed mode changes. The method is 
**         called automatically as a part of the bean 
**         SetHigh/SetLow/SetSlow methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  PWMDTY0 = (byte)(((250 * (dword)RatioStore) + 32768) >> 16); /* Calculate new value according to the given ratio */
}

/*
** ===================================================================
**     Method      :  PWM8_Enable (bean PWM)
**
**     Description :
**         This method enables the signal generation 
**     Parameters  : None
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM8_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
    HWEnDi();                          /* Enable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM8_Disable (bean PWM)
**
**     Description :
**         Disables the bean - it stops the signal generation and events calling.
**     Parameters  : None
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM8_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    HWEnDi();                          /* Disable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM8_SetRatio16 (bean PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Ratio      - Ratio is expressed as an 16-bit unsigned integer
**                      number. 0 - 65535 value is proportional
**                      to ratio 0 - 100%
**         Note: Calculated duty depends on the timer possibilities
**               and on the selected period.
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM8_SetRatio16(word Ratio)
{
  RatioStore = Ratio;                  /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM8_SetDutyUS (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 65535 us in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PWM8_SetDutyUS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  PE_Timer_LngMul((dword)Time,(dword)562949953,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi4(rtval[0],rtval[1],&RatioStore)) { /* Is the result greater or equal than 65536 ? */
    RatioStore = 65535;                /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM8_SetDutyMS (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 500 ms in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PWM8_SetDutyMS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  if (Time > 500) {                    /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
  PE_Timer_LngMul((dword)Time,(dword)2199023256,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0],rtval[1],&RatioStore)) { /* Is the result greater or equal than 65536 ? */
    RatioStore = 65535;                /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM8_Init (bean PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PWM8_Init(void)
{
  /* PWMCNT0: BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg8(PWMCNT0, 0);                 /* Reset Counter */ 
  /* PWMSDN: PWMIF=1,PWMIE=0,PWMRSTRT=0,PWMLVL=0,??=0,PWM7IN=0,PWM7INL=0,PWM7ENA=0 */
  setReg8(PWMSDN, 128);                /* Emergency shutdown feature settings */ 
  RatioStore = 13107;                  /* Store initial value of the ratio */
  EnUser = TRUE;                       /* Enable device */
  /* PWMDTY0: BIT7=0,BIT6=0,BIT5=1,BIT4=1,BIT3=0,BIT2=0,BIT1=1,BIT0=0 */
  setReg8(PWMDTY0, 50);                /* Store initial value to the duty-compare register */ 
  /* PWMPER0: BIT7=1,BIT6=1,BIT5=1,BIT4=1,BIT3=1,BIT2=0,BIT1=1,BIT0=0 */
  setReg8(PWMPER0, 250);               /* and to the period register */ 
  /* PWMPRCLK: ??=0,PCKB2=0,PCKB1=0,PCKB0=0,??=0,PCKA2=1,PCKA1=0,PCKA0=1 */
  setReg8(PWMPRCLK, 5);                /* Set prescaler register */ 
  /* PWMSCLA: BIT7=1,BIT6=1,BIT5=1,BIT4=1,BIT3=1,BIT2=0,BIT1=1,BIT0=0 */
  setReg8(PWMSCLA, 250);               /* Set scale register */ 
  /* PWMCLK: PCLK0=1 */
  setReg8Bits(PWMCLK, 1);              /* Select clock source */ 
  HWEnDi();                            /* Enable/disable device according to status flags */
}

/* END PWM8. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/