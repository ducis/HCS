/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Bit8.H
**     Project   : ProjectDIO
**     Processor : MC9S12XS128MAL
**     Beantype  : BitIO
**     Version   : Bean 02.072, Driver 03.12, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 14:19
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       27            |  PB3
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTB     [1]
**         Port control register       : DDRB      [3]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Bit8_GetVal(void);
**         PutVal - void Bit8_PutVal(bool Val);
**         ClrVal - void Bit8_ClrVal(void);
**         SetVal - void Bit8_SetVal(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef Bit8_H_
#define Bit8_H_

/* MODULE Bit8. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG Bit8_CODE
/*
** ===================================================================
**     Method      :  Bit8_GetVal (bean BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Bit8_GetVal() ( \
    (bool)((getReg8(PORTB) & 8))       /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  Bit8_PutVal (bean BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Bit8_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Bit8_ClrVal (bean BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit8_ClrVal() ( \
    (void)clrReg8Bits(PORTB, 8)        /* PB3=0 */ \
  )

/*
** ===================================================================
**     Method      :  Bit8_SetVal (bean BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit8_SetVal() ( \
    (void)setReg8Bits(PORTB, 8)        /* PB3=1 */ \
  )

#pragma CODE_SEG DEFAULT

/* END Bit8. */
#endif /* #ifndef __Bit8_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
