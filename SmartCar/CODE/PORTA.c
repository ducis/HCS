/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PORTA.C
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.10, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-9, 16:49
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
**                    0      |    57   |   PA0_ADDR8_DATA8
**                    1      |    58   |   PA1_ADDR9_DATA9
**                    2      |    59   |   PA2_ADDR10_DATA10
**                    3      |    60   |   PA3_ADDR11_DATA11
**                    4      |    61   |   PA4_ADDR12_DATA12
**                    5      |    62   |   PA5_ADDR13_DATA13
**                    6      |    63   |   PA6_ADDR14_DATA14
**                    7      |    64   |   PA7_ADDR15_DATA15
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool PORTA_GetDir(void);
**         GetVal - byte PORTA_GetVal(void);
**         PutVal - void PORTA_PutVal(byte Val);
**         GetBit - bool PORTA_GetBit(byte Bit);
**         PutBit - void PORTA_PutBit(byte Bit, bool Val);
**         SetBit - void PORTA_SetBit(byte Bit);
**         ClrBit - void PORTA_ClrBit(byte Bit);
**         NegBit - void PORTA_NegBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE PORTA. */

#include "PORTA.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu112.h"

#pragma DATA_SEG PORTA_DATA
#pragma CODE_SEG PORTA_CODE
#pragma CONST_SEG PORTA_CONST          /* Constant section for this module */
/*
** ===================================================================
**     Method      :  PORTA_GetMsk (bean ByteIO)
**
**     Description :
**         The method returns a bit mask which corresponds to the 
**         required bit position.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static const byte PORTA_Table[8] = {
  1, 2, 4, 8, 16, 32, 64, 128
};                                     /* Table of mask constants */

static byte PORTA_GetMsk (byte PinIndex)
{
  return PORTA_Table[PinIndex];        /* Return appropriate bit mask */
}

/*
** ===================================================================
**     Method      :  PORTA_GetVal (bean ByteIO)
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
byte PORTA_GetVal(void)

**  This method is implemented as a macro. See PORTA.h file.  **
*/

/*
** ===================================================================
**     Method      :  PORTA_PutVal (bean ByteIO)
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
void PORTA_PutVal(byte Val)

**  This method is implemented as a macro. See PORTA.h file.  **
*/

/*
** ===================================================================
**     Method      :  PORTA_GetBit (bean ByteIO)
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
bool PORTA_GetBit(byte Bit)
{
  byte const Mask = PORTA_GetMsk(Bit); /* Temporary variable - bit mask to test */
  return (bool)((getReg8(PORTA) & Mask) == Mask); /* Test if specified bit of port data register is set */
}

/*
** ===================================================================
**     Method      :  PORTA_PutBit (bean ByteIO)
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
void PORTA_PutBit(byte Bit, bool Val)
{
  byte const Mask = PORTA_GetMsk(Bit); /* Temporary variable - put bit mask */
  if (Val) {
    setReg8Bits(PORTA, Mask);          /* [bit Bit]=1 */
  } else { /* !Val */
    clrReg8Bits(PORTA, Mask);          /* [bit Bit]=0 */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  PORTA_SetBit (bean ByteIO)
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
void PORTA_SetBit(byte Bit)
{
  byte const Mask = PORTA_GetMsk(Bit); /* Temporary variable - set bit mask */
  setReg8Bits(PORTA, Mask);            /* [bit Bit]=1 */
}

/*
** ===================================================================
**     Method      :  PORTA_ClrBit (bean ByteIO)
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
void PORTA_ClrBit(byte Bit)
{
  byte const Mask = PORTA_GetMsk(Bit); /* Temporary variable - set bit mask */
  clrReg8Bits(PORTA, Mask);            /* [bit Bit]=0 */
}

/*
** ===================================================================
**     Method      :  PORTA_NegBit (bean ByteIO)
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
void PORTA_NegBit(byte Bit)
{
  byte const Mask = PORTA_GetMsk(Bit); /* Temporary variable - set bit mask */
  invertReg8Bits(PORTA, Mask);         /* [bit Bit]=invert */
}

/*
** ===================================================================
**     Method      :  PORTA_GetDir (bean ByteIO)
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
bool PORTA_GetDir(void)

**  This method is implemented as a macro. See PORTA.h file.  **
*/


/* END PORTA. */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
