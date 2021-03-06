/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : IEE1.H
**     Project   : Project_4
**     Processor : MC9S12XS128MAA
**     Beantype  : IntEEPROM
**     Version   : Bean 02.189, Driver 01.21, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-5-3, 23:16
**     Abstract  :
**         This device "IntEEPROM" implements internal EEPROM
**     Comment   :
**         The EEPROM array is organized as rows of word (2 bytes), the EEPROM block's
**         erase sector size is 2 rows (2 words). Therefore it is preferable
**         to use word aligned data for writting - methods SetWord and SetLong -
**         with word aligned address.
**         Driver expects that all security options of EEPROM are disabled.
**         If some security option is enabled methods performing write
**         operation (such as SetWord) can return error.
**     Settings  :
**         EEPROM size                 : 8192 byte
**         Initialization:
**              Wait in methods        : Enabled
**              EEPROM clock           : 1000 kHz
**
**     Contents  :
**         SetByte - byte IEE1_SetByte(IEE1_TAddress Addr, byte Data);
**         GetByte - byte IEE1_GetByte(IEE1_TAddress Addr, byte *Data);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __IEE1
#define __IEE1

/* MODULE IEE1. */

#include "Cpu.h"


#ifndef __BWUserType_IEE1_TAddress
#define __BWUserType_IEE1_TAddress
  /* User type for addressing of the EEPROM. Actual type depends on the CPU family. */
  typedef far word * far IEE1_TAddress; /* Type of address to the EEPROM */
#endif

#pragma CODE_SEG IEE1_CODE


/* EEPROM area start address (in the format used by bean methods). */
#define IEE1_AREA_START                 ((IEE1_TAddress)1048576UL)
/* EEPROM area last address (in the format used by bean methods). */
#define IEE1_AREA_END                   ((IEE1_TAddress)1056767UL)
/* EEPROM area size (in bytes). */
#define IEE1_AREA_SIZE                  8192U
/* EEPROM area sector size: minimal erasable unit (in bytes). */
#define IEE1_AREA_SECTOR_SIZE           256U
/* TRUE if the bean setting allows clear bits of already programmed flash memory location without destruction of the value in surrounding addresses by sector erase. */
#define IEE1_ALLOW_CLEAR                (TRUE)
/* Size of programming phrase, i.e. number of bytes that must be programmed at once */
#define IEE1_PROGRAMMING_PHRASE         (2U)

#define EEPROMStart IEE1_AREA_START    /*  Start address of used EEPROM array */
#define EEPROMEnd IEE1_AREA_END        /*  End address of used EEPROM array */

/* Flags parameter of OnError event can contain following error values (values may be OR-ed together) */
/* Double bit fault detect */
#define IEE1_DOUBLE_FAULT               (2U)
/* Single bit fault detect */
#define IEE1_SINGLE_FAULT               (1U)

byte IEE1_SetByte(IEE1_TAddress Addr,byte Data);
/*
** ===================================================================
**     Method      :  IEE1_SetByte (bean IntEEPROM)
**
**     Description :
**         This method writes a given byte to a specified address in
**         EEPROM. The method also sets address pointer for <SetActByte>
**         and <GetActByte> methods (applicable only if these methods
**         are enabled). The pointer is set to address passed as the
**         parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - Address to EEPROM
**         Data            - Data to write
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_SPEED - the bean does not work in the
**                           active speed mode 
**                           - ERR_BUSY - device is busy 
**                           - ERR_VALUE - verification of written data
**                           failed (read value does not match with
**                           written value) 
**                           - ERR_NOTAVAIL - other device-specific
**                           error 
**                           - ERR_RANGE - parameter Addr is out of range
** ===================================================================
*/

byte IEE1_GetByte(IEE1_TAddress Addr,byte *Data);
/*
** ===================================================================
**     Method      :  IEE1_GetByte (bean IntEEPROM)
**
**     Description :
**         This method reads a byte from a specified EEPROM address.
**         The method also sets address pointer for <SetActByte> and
**         <GetActByte> methods (applicable only if these methods are
**         enabled). The pointer is set to address passed as the
**         parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - EEPROM Address
**       * Data            - A pointer to the returned 8-bit data
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_BUSY - device is busy 
**                           - ERR_RANGE - parameter Addr is out of range
** ===================================================================
*/

void IEE1_Init(void);
/*
** ===================================================================
**     Method      :  IEE1_Init (bean IntEEPROM)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END IEE1. */

#endif /* ifndef __IEE1 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
