/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AD1.C
**     Project   : ProjectADC
**     Processor : MC9S12XS128MAL
**     Beantype  : ADC
**     Version   : Bean 01.489, Driver 01.15, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 14:35
**     Abstract  :
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings  :
**         AD control register         : ATD0CTL4    [708]
**         User handling procedure     : not specified
**         Number of conversions       : 1
**         AD resolution               : 12-bit
**
**         Input pins
**
**              Port name              : AD0L
**              Bit number (in port)   : 0
**              Bit mask of the port   : 1
**              Port data register     : PT1AD0      [625]
**              Port control register  : DDR1AD0     [627]
**
**         Initialization:
**              Conversion             : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-16
**     Contents  :
**         Measure    - byte AD1_Measure(bool WaitForResult);
**         GetValue16 - byte AD1_GetValue16(word *Values);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/


/* MODULE AD1. */

#pragma MESSAGE DISABLE C5703          /* Disable warning C5703 "Parameter is not referenced" */
#pragma MESSAGE DISABLE C4002          /* Disable warning C4002 "Result not used is ignored" */
#pragma MESSAGE DISABLE C12056         /* Disable warning C12056 "SP debug info incorrect because of optimization or inline assembler" */

#include "AD1.h"

#pragma DATA_SEG AD1_DATA
#pragma CODE_SEG AD1_CODE
#pragma CONST_SEG AD1_CONST            /* Constant section for this module */

#define STOP            0              /* STOP state           */
#define MEASURE         1              /* MESURE state         */
#define CONTINUOUS      2              /* CONTINUOUS state      */
#define SINGLE          3              /* SINGLE state         */

static bool OutFlg;                    /* Measurement finish flag */
volatile static byte ModeFlg;          /* Current state of device */
/*
** ===================================================================
**     Method      :  AD1_MainMeasure (bean ADC)
**
**     Description :
**         The method performs the conversion of the input channels in 
**         the polling mode.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void AD1_MainMeasure(void)
{
  if (ATD0STAT0_SCF) {                 /* Is a sequence completed? */
    OutFlg = TRUE;                     /* Measured values are available */
    ModeFlg = STOP;                    /* Set the device to the stop mode */
  }
}

/*
** ===================================================================
**     Method      :  AD1_Measure (bean ADC)
**
**     Description :
**         This method performs one measurement on all channels that
**         are set in the bean inspector. (Note: If the <number of
**         conversions> is more than one the conversion of A/D channels
**         is performed specified number of times.)
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of a
**                           conversion. If <interrupt service> is
**                           disabled, A/D peripheral doesn't support
**                           measuring all channels at once or Autoscan
**                           mode property isn't enabled and at the same
**                           time the <number of channel> is greater
**                           than 1, then the WaitForResult parameter is
**                           ignored and the method waits for each
**                           result every time. If the <interrupt
**                           service> is disabled and a <number of
**                           conversions> is greater than 1, the
**                           parameter is ignored and the method also
**                           waits for each result every time.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/
byte AD1_Measure(bool WaitForResult)
{
  if (ModeFlg != STOP) {               /* Is the device in different mode than "stop"? */
    return ERR_BUSY;                   /* If yes then error */
  }
  ModeFlg = MEASURE;                   /* Set state of device to the measure mode */
  OutFlg = FALSE;                      /* Output values aren't available */
  /* ATD0CTL5: ??=0,SC=0,SCAN=0,MULT=0,CD=0,CC=0,CB=0,CA=0 */
  ATD0CTL5 = 0;                        /* Start conversions */
  if (WaitForResult) {                 /* Is WaitForResult TRUE? */
    while (ModeFlg == MEASURE) {       /* Calling MainMeasure while IDLE state occured */
      AD1_MainMeasure();               /* A/D converter handler */
    }
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_GetValue16 (bean ADC)
**
**     Description :
**         This method returns the last measured values of all channels
**         justified to the left. Compared with <GetValue> method this
**         method returns more accurate result if the <number of
**         conversions> is greater than 1 and <AD resolution> is less
**         than 16 bits. In addition, the user code dependency on <AD
**         resolution> is eliminated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/
byte AD1_GetValue16(word *Values)
{
  if (ModeFlg != STOP) {               /* Is the device in any measure mode? */
    AD1_MainMeasure();
  }
  if (!OutFlg) {                       /* Is measured value(s) available? */
    return ERR_NOTAVAIL;               /* If no then error */
  }
  *Values = ATD0DR0 << 4;              /* Save measured values to the output buffer */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_Init (bean ADC)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AD1_Init(void)
{
  OutFlg = FALSE;                      /* No measured value */
  ModeFlg = STOP;                      /* Device isn't running */
  /* ATD0CTL4: SMP2=1,SMP1=1,SMP0=1,PRS4=0,PRS3=0,PRS2=1,PRS1=1,PRS0=1 */
  ATD0CTL4 = 231;                      /* Set sample time and prescaler */
  /* ATD0CTL3: DJM=1,S8C=0,S4C=0,S2C=0,S1C=1,FIFO=0,FRZ1=0,FRZ0=0 */
  ATD0CTL3 = 136;                      /* Set ATD control register 3 */
  /* ATD0CTL0: ??=0,??=0,??=0,??=0,WRAP3=1,WRAP2=1,WRAP1=1,WRAP0=1 */
  ATD0CTL0 = 15;                       /* Set wrap around */
  /* ATD0CTL1: ETRIGSEL=0,SRES1=1,SRES0=0,SMP_DIS=0,ETRIGCH3=1,ETRIGCH2=1,ETRIGCH1=1,ETRIGCH0=1 */
  ATD0CTL1 = 79;                       /* Set resolution and discharge */
  /* ATD0CTL2: ??=0,AFFC=1,ICLKSTP=0,ETRIGLE=0,ETRIGP=0,ETRIGE=0,ASCIE=0,ACMPIE=0 */
  ATD0CTL2 = 64;                       /* Set ATD control register 2 */
}


/* END AD1. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
