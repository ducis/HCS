/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Byte1.C
**     Project   : MotorDrive
**     Processor : MC9S12XDT256BMPV
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.13, CPU db: 2.87.216
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-4-7, 22:02
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : A
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : PORTA     [0]
**         8-bit control register      : DDRA      [2]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    57   |   PA0
**                    1      |    58   |   PA1
**                    2      |    59   |   PA2
**                    3      |    60   |   PA3
**                    4      |    61   |   PA4
**                    5      |    62   |   PA5
**                    6      |    63   |   PA6
**                    7      |    64   |   PA7
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool Byte1_GetDir(void);
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

/* MODULE Byte1. */

#include "Byte1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#pragma DATA_SEG Byte1_DATA
#pragma CODE_SEG Byte1_CODE
#pragma CONST_SEG Byte1_CONST          /* Constant section for this module */
/*
** ===================================================================
**     Method      :  Byte1_GetMsk (bean ByteIO)
**
**     Description :
**         The method returns a bit mask which corresponds to the 
**         required bit position.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static const byte Byte1_Table[8] = {
  1, 2, 4, 8, 16, 32, 64, 128
};                                     /* Table of mask constants */

static byte Byte1_GetMsk (byte PinIndex)
{
  return (byte)(PinIndex<8 ? Byte1_Table[PinIndex] : 0); /* Check range and return appropriate bit mask */
}

/*
** ===================================================================
**     Method      :  Byte1_GetVal (bean ByteIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 255)
** ===================================================================
*/
/*
byte Byte1_GetVal(void)

**  This method is implemented as a macro. See Byte1.h file.  **
*/

/*
** ===================================================================
**     Method      :  Byte1_PutVal (bean ByteIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 255)
**     Returns     : Nothing
** ===================================================================
*/
/*
void Byte1_PutVal(byte Val)

**  This method is implemented as a macro. See Byte1.h file.  **
*/

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
**         Note: This bean is set to work in Output direction only.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 7)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool Byte1_GetBit(byte Bit)
{
  byte const Mask = Byte1_GetMsk(Bit); /* Temporary variable - bit mask to test */
  return (bool)((getReg8(PORTA) & Mask) == Mask); /* Test if specified bit of port data register is set */
}

/*
** ===================================================================
**     Method      :  Byte1_PutBit (bean ByteIO)
**
**     Description :
**         This method writes the new value to the specified bit
**         of the output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit (0 to 7)
**         Val        - New value of the bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_PutBit(byte Bit, bool Val)
{
  byte const Mask = Byte1_GetMsk(Bit); /* Temporary variable - put bit mask */
  if (Val) {
    setReg8Bits(PORTA, Mask);          /* [bit Bit]=1 */
  } else { /* !Val */
    clrReg8Bits(PORTA, Mask);          /* [bit Bit]=0 */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  Byte1_SetBit (bean ByteIO)
**
**     Description :
**         This method sets (sets to one) the specified bit of the
**         output value.
**         [ It is the same as "PutBit(Bit,TRUE);" ]
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to set (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_SetBit(byte Bit)
{
  byte const Mask = Byte1_GetMsk(Bit); /* Temporary variable - set bit mask */
  setReg8Bits(PORTA, Mask);            /* [bit Bit]=1 */
}

/*
** ===================================================================
**     Method      :  Byte1_ClrBit (bean ByteIO)
**
**     Description :
**         This method clears (sets to zero) the specified bit
**         of the output value.
**         [ It is the same as "PutBit(Bit,FALSE);" ]
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to clear (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_ClrBit(byte Bit)
{
  byte const Mask = Byte1_GetMsk(Bit); /* Temporary variable - set bit mask */
  clrReg8Bits(PORTA, Mask);            /* [bit Bit]=0 */
}

/*
** ===================================================================
**     Method      :  Byte1_NegBit (bean ByteIO)
**
**     Description :
**         This method negates (inverts) the specified bit of the
**         output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to invert (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void Byte1_NegBit(byte Bit)
{
  byte const Mask = Byte1_GetMsk(Bit); /* Temporary variable - set bit mask */
  invertReg8Bits(PORTA, Mask);         /* [bit Bit]=invert */
}

/*
** ===================================================================
**     Method      :  Byte1_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (always TRUE, Output only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
/*
bool Byte1_GetDir(void)

**  This method is implemented as a macro. See Byte1.h file.  **
*/


/* END Byte1. */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/