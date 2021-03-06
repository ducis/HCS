/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PE_Timer.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : PE_Timer
**     Version   : Driver 01.03
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-8, 15:12
**     Abstract  :
**         This module "PE_Timer" implements internal methods and definitions
**         used by beans working with timers.
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
#ifndef __PE_Timer
#define __PE_Timer
/*Include shared modules, which are used for whole project*/
#include "PE_types.h"
#include "PE_const.h"

/* MODULE PE_Timer. */

void PE_Timer_LngMul(dword va1, dword va2, dlong *var);
/*
** ===================================================================
**     Method      :  PE_Timer_LngMul (bean PE_Timer)
**
**     Description :
**         The method multiplies two 32 bit values and returns pointer to 
**         64 bit result.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool PE_Timer_LngHi2(dword High, dword Low, word *Out);
/*
** ===================================================================
**     Method      :  PE_Timer_LngHi2 (bean PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool PE_Timer_LngHi3(dword High, dword Low, word *Out);
/*
** ===================================================================
**     Method      :  PE_Timer_LngHi3 (bean PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


#endif /* END PE_Timer. */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
