/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AS1.H
**     Project   : Project_4
**     Processor : MC9S12XS128MAA
**     Beantype  : AsynchroSerial
**     Version   : Bean 02.454, Driver 01.19, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-5-3, 23:16
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : SCI0
**
**         Protocol
**             Init baud rate          : 57600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**
**         Registers
**             Input buffer            : SCI0DRL   [207]
**             Output buffer           : SCI0DRL   [207]
**             Control register        : SCI0CR1   [202]
**             Mode register           : SCI0CR2   [203]
**             Baud setting reg.       : SCI0BD    [200]
**             Special register        : SCI0SR1   [204]
**
**         Input interrupt
**             Vector name             : Vsci0
**             Priority                : 4
**
**         Output interrupt
**             Vector name             : Vsci0
**             Priority                : 4
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     63               |  PS0_RxD0
**            Output  |     64               |  PS1_TxD0
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar        - byte AS1_RecvChar(AS1_TComData *Chr);
**         SendChar        - byte AS1_SendChar(AS1_TComData Chr);
**         RecvBlock       - byte AS1_RecvBlock(AS1_TComData *Ptr, word Size, word *Rcv);
**         SendBlock       - byte AS1_SendBlock(AS1_TComData *Ptr, word Size, word *Snd);
**         ClearRxBuf      - byte AS1_ClearRxBuf(void);
**         ClearTxBuf      - byte AS1_ClearTxBuf(void);
**         GetCharsInRxBuf - word AS1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word AS1_GetCharsInTxBuf(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __AS1
#define __AS1

/* MODULE AS1. */

#include "Cpu.h"



#ifndef __BWUserType_AS1_TError
#define __BWUserType_AS1_TError
  typedef union {
    byte err;
    struct {
      bool OverRun  : 1;               /* Overrun error flag */
      bool Framing  : 1;               /* Framing error flag */
      bool Parity   : 1;               /* Parity error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Noise    : 1;               /* Noise error flag */
      bool Break    : 1;               /* Break detect */
      bool LINSync  : 1;               /* LIN synchronization error */
      bool BitError  : 1;              /* Bit error flag - mismatch to the expected value happened. */
    } errName;
  } AS1_TError;                        /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
#endif

#ifndef __BWUserType_AS1_TComData
#define __BWUserType_AS1_TComData
  typedef byte AS1_TComData ;          /* User type for communication. Size of this type depends on the communication data witdh. */
#endif

#pragma DATA_SEG AS1_DATA
#pragma CODE_SEG AS1_CODE

#define AS1_INP_BUF_SIZE 256           /* Input buffer size */
#define AS1_OUT_BUF_SIZE 256           /* Output buffer size */

extern word AS1_OutLen;                /* Length of output bufer's content */
extern word AS1_InpLen;                /* Length of input buffer's content */

byte AS1_RecvChar(AS1_TComData *Chr);
/*
** ===================================================================
**     Method      :  AS1_RecvChar (bean AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/

byte AS1_SendChar(AS1_TComData Chr);
/*
** ===================================================================
**     Method      :  AS1_SendChar (bean AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

byte AS1_RecvBlock(AS1_TComData *Ptr,word Size,word *Rcv);
/*
** ===================================================================
**     Method      :  AS1_RecvBlock (bean AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns the block of
**         the data and its length (and incidental error), otherwise
**         it returns an error code (it does not wait for data).
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is
**         enabled.
**         If less than requested number of characters is received
**         only the available data is copied from the receive buffer
**         to the user specified destination. The value ERR_EXEMPTY
**         is returned and the value of variable pointed by the Rcv
**         parameter is set to the number of received characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of received data
**         Size            - Size of the block
**       * Rcv             - Pointer to real number of the received
**                           data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - The receive buffer didn't
**                           contain the requested number of data.
**                           Only available data has been returned.
**                           ERR_COMMON - common error occurred (the
**                           GetError method can be used for error
**                           specification)
** ===================================================================
*/

byte AS1_SendBlock(AS1_TComData *Ptr,word Size,word *Snd);
/*
** ===================================================================
**     Method      :  AS1_SendBlock (bean AsynchroSerial)
**
**     Description :
**         Sends a block of characters to the channel.
**         This method is available only if non-zero length of the
**         output buffer is defined and the transmitter property is
**         enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of data to send
**         Size            - Size of the block
**       * Snd             - Pointer to number of data that are sent
**                           (moved to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - It was not possible to send
**                           requested number of bytes
** ===================================================================
*/

byte AS1_ClearRxBuf(void);
/*
** ===================================================================
**     Method      :  AS1_ClearRxBuf (bean AsynchroSerial)
**
**     Description :
**         Clears the receive buffer.
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte AS1_ClearTxBuf(void);
/*
** ===================================================================
**     Method      :  AS1_ClearTxBuf (bean AsynchroSerial)
**
**     Description :
**         Clears the transmit buffer.
**         This method is available only if non-zero length of the
**         output buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define AS1_GetCharsInRxBuf() (AS1_InpLen) /* Return number of chars in receive buffer */
/*
** ===================================================================
**     Method      :  AS1_GetCharsInRxBuf (bean AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         This method is available only if the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/

#define AS1_GetCharsInTxBuf() (AS1_OutLen) /* Return number of chars in the transmitter buffer */
/*
** ===================================================================
**     Method      :  AS1_GetCharsInTxBuf (bean AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the output buffer.
**         This method is available only if the transmitter property
**         is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void AS1_Interrupt(void);
#pragma CODE_SEG AS1_CODE
/*
** ===================================================================
**     Method      :  AS1_Interrupt (bean AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


void AS1_Init(void);
/*
** ===================================================================
**     Method      :  AS1_Init (bean AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and internal 
**         variables of the bean. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


#pragma CODE_SEG DEFAULT
/* END AS1. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/

#endif /* ifndef __AS1 */
