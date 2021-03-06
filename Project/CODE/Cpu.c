/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.C
**     Project   : Project
**     Processor : MC9S12XS128MAL
**     Beantype  : MC9S12XS256_112
**     Version   : Bean 01.002, Driver 02.03, CPU db: 3.00.003
**     Datasheet : MC9S12XS256RMV1 Rev. 1.03 06/2008
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 16:11
**     Abstract  :
**         This bean "MC9S12XS256_112" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE Cpu. */

#include "PWM8.h"
#include "TI1.h"
#include "TI2.h"
#include "InpB1.h"
#include "Byte1.h"
#include "Events.h"
#include "Cpu.h"

#define CGM_DELAY  1023UL

#pragma DATA_SEG DEFAULT
#pragma CODE_SEG DEFAULT


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR reegister */
#pragma CODE_SEG __NEAR_SEG NON_BANKED


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (bean MC9S12XS256_112)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  asm(BGND);
}


#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (bean MC9S12XS256_112)
**
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (bean MC9S12XS256_112)
**
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (bean MC9S12XS256_112)
**
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (bean MC9S12XS256_112)
**
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  PE_low_level_init (bean MC9S12XS256_112)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* Int. priority initialization */
  /*                                        No. Address Pri XGATE Name           Description */
  setReg8(INT_CFADDR, 112);             
  setReg8(INT_CFDATA5, 4);             /*  0x3D  0xFF7A   4   no   ivVpit0        used by PE */ 
  setReg8(INT_CFDATA7, 4);             /*  0x3F  0xFF7E   4   no   ivVapi         used by PE */ 
  /* Common initialization of the CPU registers */
  /* PWME: PWME7=0,PWME6=0,PWME5=0,PWME4=0,PWME3=0,PWME2=0,PWME1=0,PWME0=0 */
  setReg8(PWME, 0);                     
  /* PWMCTL: CON01=0,PSWAI=0,PFRZ=0 */
  clrReg8Bits(PWMCTL, 28);              
  /* PWMCAE: CAE0=0 */
  clrReg8Bits(PWMCAE, 1);               
  /* PWMPOL: PPOL0=0 */
  clrReg8Bits(PWMPOL, 1);               
  /* PTP: PTP0=0 */
  clrReg8Bits(PTP, 1);                  
  /* DDRP: DDRP0=1 */
  setReg8Bits(DDRP, 1);                 
  /* PITCFLMT: PITE=0 */
  clrReg8Bits(PITCFLMT, 128);           
  /* PITCE: PCE0=0 */
  clrReg8Bits(PITCE, 1);                
  /* PITTF: PTF0=1 */
  setReg8Bits(PITTF, 1);                
  /* PITINTE: PINTE0=1 */
  setReg8Bits(PITINTE, 1);              
  /* PITMTLD1: PMTLD7=0,PMTLD6=1,PMTLD5=1,PMTLD4=1,PMTLD3=1,PMTLD2=1,PMTLD1=0,PMTLD0=0 */
  setReg8(PITMTLD1, 124);               
  /* PITMUX: PMUX0=1 */
  setReg8Bits(PITMUX, 1);               
  /* VREGAPICL: APICLK=1,APIFE=0,APIE=1,APIF=1 */
  clrSetReg8Bits(VREGAPICL, 4, 131);    
  /* PORTB: PB7=0,PB6=0,PB5=0,PB4=0,PB3=0,PB2=0,PB1=0,PB0=0 */
  setReg8(PORTB, 0);                    
  /* PUCR: PUPBE=0 */
  clrReg8Bits(PUCR, 2);                 
  /* DDRB: DDRB7=1,DDRB6=1,DDRB5=1,DDRB4=1,DDRB3=1,DDRB2=1,DDRB1=1,DDRB0=1 */
  setReg8(DDRB, 255);                   
  /* CRGINT: LOCKIE=0,SCMIE=0 */
  clrReg8Bits(CRGINT, 18);              
  /* VREGCTRL: LVIE=0 */
  clrReg8Bits(VREGCTRL, 2);             
  /* COPCTL: WCOP=0,RSBCK=0,WRTMASK=0,??=0,??=0,CR2=0,CR1=0,CR0=0 */
  setReg8(COPCTL, 0);                   
  /* RDRIV: RDPK=0,RDPE=0,RDPB=0,RDPA=0 */
  clrReg8Bits(RDRIV, 147);              
  /* RDRH: RDRH7=0,RDRH6=0,RDRH5=0,RDRH4=0,RDRH3=0,RDRH2=0,RDRH1=0,RDRH0=0 */
  setReg8(RDRH, 0);                     
  /* RDRJ: RDRJ7=0,RDRJ6=0,RDRJ1=0,RDRJ0=0 */
  clrReg8Bits(RDRJ, 195);               
  /* RDRM: RDRM7=0,RDRM6=0,RDRM5=0,RDRM4=0,RDRM3=0,RDRM2=0,RDRM1=0,RDRM0=0 */
  setReg8(RDRM, 0);                     
  /* RDRP: RDRP7=0,RDRP6=0,RDRP5=0,RDRP4=0,RDRP3=0,RDRP2=0,RDRP1=0,RDRP0=0 */
  setReg8(RDRP, 0);                     
  /* RDRS: RDRS7=0,RDRS6=0,RDRS5=0,RDRS4=0,RDRS3=0,RDRS2=0,RDRS1=0,RDRS0=0 */
  setReg8(RDRS, 0);                     
  /* RDRT: RDRT7=0,RDRT6=0,RDRT5=0,RDRT4=0,RDRT3=0,RDRT2=0,RDRT1=0,RDRT0=0 */
  setReg8(RDRT, 0);                     
  /* RDR0AD0: RDR0AD07=0,RDR0AD06=0,RDR0AD05=0,RDR0AD04=0,RDR0AD03=0,RDR0AD02=0,RDR0AD01=0,RDR0AD00=0 */
  setReg8(RDR0AD0, 0);                  
  /* RDR1AD0: RDR1AD07=0,RDR1AD06=0,RDR1AD05=0,RDR1AD04=0,RDR1AD03=0,RDR1AD02=0,RDR1AD01=0,RDR1AD00=0 */
  setReg8(RDR1AD0, 0);                  
  /* IRQCR: IRQEN=0 */
  clrReg8Bits(IRQCR, 64);               
  /* VREGAPIR: APIR7=1,APIR5=1,APIR4=1,APIR3=1,APIR2=1,APIR1=1,APIR0=1 */
  setReg16Bits(VREGAPIR, 191);          
  /* ### MC9S12XS256_112 "Cpu" init code ... */
  /* ### Programable pulse generation "PWM8" init code ... */
  PWM8_Init();
  /* ### TimerInt "TI1" init code ... */
  /* PITLD0: PLD15=1,PLD14=1,PLD13=1,PLD12=1,PLD11=1,PLD10=0,PLD9=1,PLD8=0,PLD7=0,PLD6=0,PLD5=0,PLD4=0,PLD3=0,PLD2=0,PLD1=0,PLD0=0 */
  setReg16(PITLD0, 64000);             /* Store given value to the compare register */ 
  /* PITCE: PCE0=1 */
  setReg8Bits(PITCE, 1);               /* Enable Timer */ 
  /* ### TimerInt "TI2" init code ... */
  /* ### InputPin "InpB1" init code ... */
  /* ### ByteIO "Byte1" init code ... */
 /* Common peripheral initialization - ENABLE */
  /* PITCFLMT: PITE=1 */
  setReg8Bits(PITCFLMT, 128);           
  /* VREGAPICL: APIFE=1 */
  setReg8Bits(VREGAPICL, 4);            
  __EI();                              /* Enable interrupts */
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED

/*
** ===================================================================
**     Method      :  _EntryPoint (bean MC9S12XS256_112)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */
#pragma OPTION ADD "-Onf"              /* 'Create Sub-Functions with Common Code optimalization' must be disabled because stack is not yet initialized */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC9S12XS256_112 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* MMCCTL1: MGRAMON=0,??=0,DFIFRON=0,PGMIFRON=0,??=0,??=0,??=0,??=0 */
  setReg8(MMCCTL1, 0);                  
  /* DIRECT: DP15=0,DP14=0,DP13=0,DP12=0,DP11=0,DP10=0,DP9=0,DP8=0 */
  setReg8(DIRECT, 0);                   
  /* IVBR: IVB_ADDR=255 */
  setReg8(IVBR, 255);                   
  /* ECLKCTL: NECLK=0,NCLKX2=1,DIV16=0,EDIV4=0,EDIV3=0,EDIV2=0,EDIV1=0,EDIV0=0 */
  setReg8(ECLKCTL, 64);                 
  /*  System clock initialization */
  /* CLKSEL: PLLSEL=0,PSTP=0,XCLKS=0,??=0,PLLWAI=0,??=0,RTIWAI=0,COPWAI=0 */
  setReg8(CLKSEL, 0);                  /* Select clock source from XTAL and set bits in CLKSEL reg. */ 
  /* PLLCTL: CME=1,PLLON=0,FM1=0,FM0=0,FSTWKP=0,PRE=0,PCE=0,SCME=1 */
  setReg8(PLLCTL, 129);                /* Disable the PLL */ 
  /* VREGHTCL: ??=0,??=0,VSEL=0,VAE=1,HTEN=0,HTDS=0,HTIE=0,HTIF=0 */
  setReg8(VREGHTCL, 16);                
  /*** End of PE initialization code after reset ***/
  __asm("jmp _Startup");               /* Jump to C startup code */
}

#pragma CODE_SEG DEFAULT
/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
