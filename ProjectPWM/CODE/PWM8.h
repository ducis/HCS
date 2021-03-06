/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PWM8.H
**     Project   : ProjectPWM
**     Processor : MC9S12XS128MAL
**     Beantype  : PWM
**     Version   : Bean 02.207, Driver 01.14, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 13:47
**     Abstract  :
**         This bean implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       112           |  PP4_KWP4_PWM4
**             ----------------------------------------------------
**
**         Timer name                  : PWM4 [8-bit]
**         Counter                     : PWMCNT4   [784]
**         Mode register               : PWMCTL    [773]
**         Run register                : PWME      [768]
**         Prescaler                   : PWMPRCLK  [771]
**         Compare 1 register          : PWMPER4   [792]
**         Compare 2 register          : PWMDTY4   [800]
**         Flip-flop 1 register        : PWMPOL    [769]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : P
**         Bit number (in port)        : 4
**         Bit mask of the port        : 16
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
**             Clock                   : 125 Hz
**           Initial value of            period        pulse width (ratio 49.6%)
**             Xtal ticks              : 16000000      7936000
**             microseconds            : 1000000       496000
**             milliseconds            : 1000          496
**             seconds                 : 1             0
**             seconds (real)          : 1.0000000     0.4960000
**
**     Contents  :
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

#ifndef __PWM8
#define __PWM8

/* MODULE PWM8. */

#include "Cpu.h"

#pragma CODE_SEG PWM8_CODE

#define PWM8_PERIOD_VALUE    125UL     /* Initial period value in ticks of the timer */
#define PWM8_PERIOD_VALUE_HIGH 125UL   /* Initial period value in ticks of the timer in high speed mode */

byte PWM8_SetRatio16(word Ratio);
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

byte PWM8_SetDutyUS(word Time);
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

byte PWM8_SetDutyMS(word Time);
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
**                      (0 to 1000 ms in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void PWM8_Init(void);
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

#pragma CODE_SEG DEFAULT

/* END PWM8. */

#endif /* ifndef __PWM8 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
