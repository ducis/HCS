/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Byte1.H
**     Project   : ProjectPWM
**     Processor : MC9S12XS128MAL
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.13, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 13:50
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : B
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 255 = 0FFH
**         Initial pull option         : off
**
**         8-bit data register         : PORTB     [1]
**         8-bit control register      : DDRB      [3]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    24   |   PB0
**                    1      |    25   |   PB1
**                    2      |    26   |   PB2
**                    3      |    27   |   PB3
**                    4      |    28   |   PB4
**                    5      |    29   |   PB5
**                    6      |    30   |   PB6
**                    7      |    31   |   PB7
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool Byte1_GetDir(void);
**         SetDir - void Byte1_SetDir(bool Dir);
**         GetVal - byte Byte1_GetVal(void);
**         PutVal - void Byte1_PutVal(byte Val);
**         GetBit - bool Byte1_GetBit(byte Bit);
**         PutBit - void Byte1_PutBit(byte Bit, bool Val);
**         SetBit - void Byte1_SetBit(byte Bit);
**         ClrBit - void Byte1_ClrBit(byte Bit);
**         NegBit - void Byte1_NegBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef Byte1_H_
#define Byte1_H_

/* MODULE Byte1. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#pragma CODE_SEG Byte1_CODE
/*
** ===================================================================
**     Method      :  Byte1_GetVal (bean ByteIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 255)
** ===================================================================
*/
#define Byte1_GetVal() ( \
    getReg8(PORTB)                     /* Evaluate to port data */ \
  )

/*
** ===================================================================
**     Method      :  Byte1_PutVal (bean ByteIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pins
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 255)
**     Returns     : Nothing
** ===================================================================
*/
#define Byte1_PutVal(Val) ( \
    (void)setReg8(PORTB, Val)          /* PB0-PB7=Val[bits 0-7] */, \
    Shadow_B = (Val)                   /* Set-up shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  Byte1_GetBit (bean ByteIO)
**
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 7)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool Byte1_GetBit(byte Bit);

/*
** ===================================================================
**     Method      :  Byte1_PutBit (bean ByteIO)
**
**     Description :
**         This method writes the new value to the specified bit
**         of the output value.
**           a) direction = Input  : sets the value of the specified
**                                   bit; this operation will be
**                                   shown on output after the
**                                   direction has been switched to
**                                   output (SetDir(TRUE);)
**           b) direction = Output : directly writes the value of the
**                                   bit to the appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit (0 to 7)
**         Val        - New value of the bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_PutBit(byte Bit, bool Val);

/*
** ===================================================================
**     Method      :  Byte1_SetBit (bean ByteIO)
**
**     Description :
**         This method sets (sets to one) the specified bit of the
**         output value.
**         [ It is the same as "PutBit(Bit,TRUE);" ]
**           a) direction = Input  : sets the specified bit to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to set (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_SetBit(byte Bit);

/*
** ===================================================================
**     Method      :  Byte1_ClrBit (bean ByteIO)
**
**     Description :
**         This method clears (sets to zero) the specified bit
**         of the output value.
**         [ It is the same as "PutBit(Bit,FALSE);" ]
**           a) direction = Input  : sets the specified bit to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   beenswitched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to clear (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_ClrBit(byte Bit);

/*
** ===================================================================
**     Method      :  Byte1_NegBit (bean ByteIO)
**
**     Description :
**         This method negates (inverts) the specified bit of the
**         output value.
**           a) direction = Input  : inverts the specified bit;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly inverts the value
**                                   of the appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to invert (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_NegBit(byte Bit);

/*
** ===================================================================
**     Method      :  Byte1_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define Byte1_GetDir() ( \
    (bool)(getReg8(DDRB))              /* Return port direction, 0==GPI, nonzero==GPO */ \
  )

/*
** ===================================================================
**     Method      :  Byte1_SetDir (bean ByteIO)
**
**     Description :
**         This method sets direction of the bean.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_SetDir(bool Dir);

#pragma CODE_SEG DEFAULT

/* END Byte1. */
#endif /* #ifndef __Byte1_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
