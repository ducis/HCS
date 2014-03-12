/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Servo2.C
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : PWM
**     Version   : Bean 02.207, Driver 01.14, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-8, 15:12
**     Abstract  :
**         This bean implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       1             |  PP3_SS1_PWM3_KWP3
**             ----------------------------------------------------
**
**         Timer name                  : PWM23 [16-bit]
**         Counter                     : PWMCNT23  [174]
**         Mode register               : PWMCTL    [165]
**         Run register                : PWME      [160]
**         Prescaler                   : PWMPRCLK  [163]
**         Compare 1 register          : PWMPER23  [182]
**         Compare 2 register          : PWMDTY23  [190]
**         Flip-flop 1 register        : PWMPOL    [161]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : P
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
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
**             Clock                   : 8000000 Hz
**           Initial value of            period        pulse width (ratio 7.575%)
**             Xtal ticks              : 40000         3030
**             microseconds            : 2500          189
**             milliseconds            : 2             0
**             seconds (real)          : 0.0025000     0.0001894
**
**     Contents  :
**         SetRatio16     - byte Servo2_SetRatio16(word Ratio);
**         SetDutyTicks16 - byte Servo2_SetDutyTicks16(word Ticks);
**         SetDutyUS      - byte Servo2_SetDutyUS(word Time);
**         SetDutyMS      - byte Servo2_SetDutyMS(word Time);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/


/* MODULE Servo2. */

#include "Servo2.h"

#pragma DATA_SEG Servo2_DATA
#pragma CODE_SEG Servo2_CODE

static word RatioStore;                /* Ratio of L-level to H-level */


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
  /* PWMDTY23 = (PWMPER23 * (dword)RatioStore + 32768) / 65535;  Calculate new value according to the given ratio */
  asm {
    LDY    PWMPER23
    LDD    RatioStore
    EMUL
    ADDD   #32768
    EXG    D,Y
    ADCB   #0
    ADCA   #0
    LDX    #65535
    EXG    D,Y
    EDIV
    STY    PWMDTY23
  }
}

/*
** ===================================================================
**     Method      :  Servo2_SetRatio16 (bean PWM)
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
byte Servo2_SetRatio16(word Ratio)
{
  RatioStore = Ratio;                  /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Servo2_SetDutyTicks16 (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in main oscillator (usualy External
**         osc., internal osc. if exits and external osc. is disabled)
**         ticks as a 16-bit unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ticks           - Duty to set in main oscillator ticks
**                      (0 to 40000 ticks in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte Servo2_SetDutyTicks16(word Ticks)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  PE_Timer_LngMul((dword)Ticks,(dword)27487791,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0],rtval[1],&RatioStore)) { /* Is the result greater or equal than 65536 ? */
    RatioStore = 65535;                /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Servo2_SetDutyUS (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 2500 us in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte Servo2_SetDutyUS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  PE_Timer_LngMul((dword)Time,(dword)439804651,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0],rtval[1],&RatioStore)) { /* Is the result greater or equal than 65536 ? */
    RatioStore = 65535;                /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Servo2_SetDutyMS (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 2 ms in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte Servo2_SetDutyMS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  PE_Timer_LngMul((dword)Time,(dword)1717986918,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi2(rtval[0],rtval[1],&RatioStore)) { /* Is the result greater or equal than 65536 ? */
    RatioStore = 65535;                /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Servo2_Init (bean PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Servo2_Init(void)
{
  /* PWMCNT23: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(PWMCNT23, 0);               /* Reset Counter */ 
  /* PWMSDN: PWMIF=1,PWMIE=0,PWMRSTRT=0,PWMLVL=0,??=0,PWM7IN=0,PWM7INL=0,PWM7ENA=0 */
  setReg8(PWMSDN, 128);                /* Emergency shutdown feature settings */ 
  RatioStore = 4964;                   /* Store initial value of the ratio */
  /* PWMDTY23: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=1,BIT9=0,BIT8=1,BIT7=1,BIT6=1,BIT5=1,BIT4=0,BIT3=1,BIT2=0,BIT1=1,BIT0=1 */
  setReg16(PWMDTY23, 1515);            /* Store initial value to the duty-compare register */ 
  /* PWMPER23: BIT15=0,BIT14=1,BIT13=0,BIT12=0,BIT11=1,BIT10=1,BIT9=1,BIT8=0,BIT7=0,BIT6=0,BIT5=1,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(PWMPER23, 20000);           /* and to the period register */ 
  /* PWMPRCLK: ??=0,PCKB2=0,PCKB1=0,PCKB0=0,??=0,PCKA2=0,PCKA1=0,PCKA0=0 */
  setReg8(PWMPRCLK, 0);                /* Set prescaler register */ 
  /* PWMSCLB: BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=1 */
  setReg8(PWMSCLB, 1);                 /* Set scale register */ 
  /* PWMCLK: PCLK3=0 */
  clrReg8Bits(PWMCLK, 8);              /* Select clock source */ 
  /* PWME: PWME3=1 */
  setReg8Bits(PWME, 8);                /* Run counter */ 
}

/* END Servo2. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
