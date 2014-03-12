/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : MainMotor.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : PWM
**     Version   : Bean 02.207, Driver 01.14, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-8, 15:28
**     Abstract  :
**         This bean implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       112           |  PP4_PWM4_KWP4
**             ----------------------------------------------------
**
**         Timer name                  : PWM4 [8-bit]
**         Counter                     : PWMCNT4   [176]
**         Mode register               : PWMCTL    [165]
**         Run register                : PWME      [160]
**         Prescaler                   : PWMPRCLK  [163]
**         Compare 1 register          : PWMPER4   [184]
**         Compare 2 register          : PWMDTY4   [192]
**         Flip-flop 1 register        : PWMPOL    [161]
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
**              Timer                  : Disabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 8000000 Hz
**           Initial value of            period        pulse width (ratio 50%)
**             Xtal ticks              : 200           100
**             microseconds            : 12            6
**             seconds (real)          : 0.0000125     0.0000063
**
**     Contents  :
**         Enable         - byte MainMotor_Enable(void);
**         Disable        - byte MainMotor_Disable(void);
**         SetDutyTicks16 - byte MainMotor_SetDutyTicks16(word Ticks);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __MainMotor
#define __MainMotor

/* MODULE MainMotor. */

#include "Cpu112.h"

#pragma CODE_SEG MainMotor_CODE

#define MainMotor_PERIOD_VALUE 100UL   /* Initial period value in ticks of the timer */
#define MainMotor_PERIOD_VALUE_HIGH 100UL /* Initial period value in ticks of the timer in high speed mode */

byte MainMotor_Enable(void);
/*
** ===================================================================
**     Method      :  MainMotor_Enable (bean PWM)
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

byte MainMotor_Disable(void);
/*
** ===================================================================
**     Method      :  MainMotor_Disable (bean PWM)
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

byte MainMotor_SetDutyTicks16(word Ticks);
/*
** ===================================================================
**     Method      :  MainMotor_SetDutyTicks16 (bean PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in main oscillator (usualy External
**         osc., internal osc. if exits and external osc. is disabled)
**         ticks as a 16-bit unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ticks           - Duty to set in main oscillator ticks
**                      (0 to 200 ticks in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void MainMotor_Init(void);
/*
** ===================================================================
**     Method      :  MainMotor_Init (bean PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END MainMotor. */

#endif /* ifndef __MainMotor */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/