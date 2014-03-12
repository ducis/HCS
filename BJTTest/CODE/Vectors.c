/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Vectors.C
**     Project   : BJTTest
**     Processor : MC9S12XDT256BMPV
**     Version   : Bean 02.002, Driver 02.03, CPU db: 2.87.216
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-3-27, 11:51
**     Abstract  :
**         This bean "MC9S12XDT384_112" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/
#include "Cpu.h"
#include "Bit1.h"

/* ISR prototype */
typedef void (*near tIsrFunc)(void);
const tIsrFunc _InterruptVectorTable[] @0xFF10 = { /* Interrupt vector table */
  /* ISR name                               No.  Address Pri XGATE Name          Description */
  Cpu_Interrupt,                        /* 0x08  0xFF10   -   -    ivVsi         unused by PE */
  Cpu_Interrupt,                        /* 0x09  0xFF12   1   no   ivReserved119 unused by PE */
  Cpu_Interrupt,                        /* 0x0A  0xFF14   1   no   ivReserved118 unused by PE */
  Cpu_Interrupt,                        /* 0x0B  0xFF16   1   no   ivReserved117 unused by PE */
  Cpu_Interrupt,                        /* 0x0C  0xFF18   1   no   ivReserved116 unused by PE */
  Cpu_Interrupt,                        /* 0x0D  0xFF1A   1   no   ivReserved115 unused by PE */
  Cpu_Interrupt,                        /* 0x0E  0xFF1C   1   no   ivReserved114 unused by PE */
  Cpu_Interrupt,                        /* 0x0F  0xFF1E   1   no   ivReserved113 unused by PE */
  Cpu_Interrupt,                        /* 0x10  0xFF20   1   no   ivReserved112 unused by PE */
  Cpu_Interrupt,                        /* 0x11  0xFF22   1   no   ivReserved111 unused by PE */
  Cpu_Interrupt,                        /* 0x12  0xFF24   1   no   ivReserved110 unused by PE */
  Cpu_Interrupt,                        /* 0x13  0xFF26   1   no   ivReserved109 unused by PE */
  Cpu_Interrupt,                        /* 0x14  0xFF28   1   no   ivReserved108 unused by PE */
  Cpu_Interrupt,                        /* 0x15  0xFF2A   1   no   ivReserved107 unused by PE */
  Cpu_Interrupt,                        /* 0x16  0xFF2C   1   no   ivReserved106 unused by PE */
  Cpu_Interrupt,                        /* 0x17  0xFF2E   1   no   ivReserved105 unused by PE */
  Cpu_Interrupt,                        /* 0x18  0xFF30   1   no   ivReserved104 unused by PE */
  Cpu_Interrupt,                        /* 0x19  0xFF32   1   no   ivReserved103 unused by PE */
  Cpu_Interrupt,                        /* 0x1A  0xFF34   1   no   ivReserved102 unused by PE */
  Cpu_Interrupt,                        /* 0x1B  0xFF36   1   no   ivReserved101 unused by PE */
  Cpu_Interrupt,                        /* 0x1C  0xFF38   1   no   ivReserved100 unused by PE */
  Cpu_Interrupt,                        /* 0x1D  0xFF3A   1   no   ivReserved99  unused by PE */
  Cpu_Interrupt,                        /* 0x1E  0xFF3C   1   no   ivReserved98  unused by PE */
  Cpu_Interrupt,                        /* 0x1F  0xFF3E   1   no   ivReserved97  unused by PE */
  Cpu_Interrupt,                        /* 0x20  0xFF40   1   no   ivReserved96  unused by PE */
  Cpu_Interrupt,                        /* 0x21  0xFF42   1   no   ivReserved95  unused by PE */
  Cpu_Interrupt,                        /* 0x22  0xFF44   1   no   ivReserved94  unused by PE */
  Cpu_Interrupt,                        /* 0x23  0xFF46   1   no   ivReserved93  unused by PE */
  Cpu_Interrupt,                        /* 0x24  0xFF48   1   no   ivReserved92  unused by PE */
  Cpu_Interrupt,                        /* 0x25  0xFF4A   1   no   ivReserved91  unused by PE */
  Cpu_Interrupt,                        /* 0x26  0xFF4C   1   no   ivReserved90  unused by PE */
  Cpu_Interrupt,                        /* 0x27  0xFF4E   1   no   ivReserved89  unused by PE */
  Cpu_Interrupt,                        /* 0x28  0xFF50   1   no   ivReserved88  unused by PE */
  Cpu_Interrupt,                        /* 0x29  0xFF52   1   no   ivReserved87  unused by PE */
  Cpu_Interrupt,                        /* 0x2A  0xFF54   1   no   ivReserved86  unused by PE */
  Cpu_Interrupt,                        /* 0x2B  0xFF56   1   no   ivReserved85  unused by PE */
  Cpu_Interrupt,                        /* 0x2C  0xFF58   1   no   ivReserved84  unused by PE */
  Cpu_Interrupt,                        /* 0x2D  0xFF5A   1   no   ivReserved83  unused by PE */
  Cpu_Interrupt,                        /* 0x2E  0xFF5C   1   no   ivReserved82  unused by PE */
  Cpu_Interrupt,                        /* 0x2F  0xFF5E   1   no   ivReserved81  unused by PE */
  Cpu_Interrupt,                        /* 0x30  0xFF60   1   -    ivVxsramav    unused by PE */
  Cpu_Interrupt,                        /* 0x31  0xFF62   1   -    ivVxsei       unused by PE */
  Cpu_Interrupt,                        /* 0x32  0xFF64   1   no   ivVxst7       unused by PE */
  Cpu_Interrupt,                        /* 0x33  0xFF66   1   no   ivVxst6       unused by PE */
  Cpu_Interrupt,                        /* 0x34  0xFF68   1   no   ivVxst5       unused by PE */
  Cpu_Interrupt,                        /* 0x35  0xFF6A   1   no   ivVxst4       unused by PE */
  Cpu_Interrupt,                        /* 0x36  0xFF6C   1   no   ivVxst3       unused by PE */
  Cpu_Interrupt,                        /* 0x37  0xFF6E   1   no   ivVxst2       unused by PE */
  Cpu_Interrupt,                        /* 0x38  0xFF70   1   no   ivVxst1       unused by PE */
  Cpu_Interrupt,                        /* 0x39  0xFF72   1   no   ivVxst0       unused by PE */
  Cpu_Interrupt,                        /* 0x3A  0xFF74   1   no   ivVpit3       unused by PE */
  Cpu_Interrupt,                        /* 0x3B  0xFF76   1   no   ivVpit2       unused by PE */
  Cpu_Interrupt,                        /* 0x3C  0xFF78   1   no   ivVpit1       unused by PE */
  Cpu_Interrupt,                        /* 0x3D  0xFF7A   1   no   ivVpit0       unused by PE */
  Cpu_Interrupt,                        /* 0x3E  0xFF7C   1   no   ivVReserved65 unused by PE */
  Cpu_Interrupt,                        /* 0x3F  0xFF7E   1   no   ivVapi        unused by PE */
  Cpu_Interrupt,                        /* 0x40  0xFF80   1   no   ivVlvi        unused by PE */
  Cpu_Interrupt,                        /* 0x41  0xFF82   1   no   ivVReserved62 unused by PE */
  Cpu_Interrupt,                        /* 0x42  0xFF84   1   no   ivVReserved61 unused by PE */
  Cpu_Interrupt,                        /* 0x43  0xFF86   1   no   ivVsci4       unused by PE */
  Cpu_Interrupt,                        /* 0x44  0xFF88   1   no   ivVReserved59 unused by PE */
  Cpu_Interrupt,                        /* 0x45  0xFF8A   1   no   ivVsci2       unused by PE */
  Cpu_Interrupt,                        /* 0x46  0xFF8C   1   no   ivVpwmesdn    unused by PE */
  Cpu_Interrupt,                        /* 0x47  0xFF8E   1   no   ivVportp      unused by PE */
  Cpu_Interrupt,                        /* 0x48  0xFF90   1   no   ivVcan4tx     unused by PE */
  Cpu_Interrupt,                        /* 0x49  0xFF92   1   no   ivVcan4rx     unused by PE */
  Cpu_Interrupt,                        /* 0x4A  0xFF94   1   no   ivVcan4err    unused by PE */
  Cpu_Interrupt,                        /* 0x4B  0xFF96   1   no   ivVcan4wkup   unused by PE */
  Cpu_Interrupt,                        /* 0x4C  0xFF98   1   no   ivVReserved51 unused by PE */
  Cpu_Interrupt,                        /* 0x4D  0xFF9A   1   no   ivVReserved50 unused by PE */
  Cpu_Interrupt,                        /* 0x4E  0xFF9C   1   no   ivVReserved49 unused by PE */
  Cpu_Interrupt,                        /* 0x4F  0xFF9E   1   no   ivVReserved48 unused by PE */
  Cpu_Interrupt,                        /* 0x50  0xFFA0   1   no   ivVReserved47 unused by PE */
  Cpu_Interrupt,                        /* 0x51  0xFFA2   1   no   ivVReserved46 unused by PE */
  Cpu_Interrupt,                        /* 0x52  0xFFA4   1   no   ivVReserved45 unused by PE */
  Cpu_Interrupt,                        /* 0x53  0xFFA6   1   no   ivVReserved44 unused by PE */
  Cpu_Interrupt,                        /* 0x54  0xFFA8   1   no   ivVcan1tx     unused by PE */
  Cpu_Interrupt,                        /* 0x55  0xFFAA   1   no   ivVcan1rx     unused by PE */
  Cpu_Interrupt,                        /* 0x56  0xFFAC   1   no   ivVcan1err    unused by PE */
  Cpu_Interrupt,                        /* 0x57  0xFFAE   1   no   ivVcan1wkup   unused by PE */
  Cpu_Interrupt,                        /* 0x58  0xFFB0   1   no   ivVcan0tx     unused by PE */
  Cpu_Interrupt,                        /* 0x59  0xFFB2   1   no   ivVcan0rx     unused by PE */
  Cpu_Interrupt,                        /* 0x5A  0xFFB4   1   no   ivVcan0err    unused by PE */
  Cpu_Interrupt,                        /* 0x5B  0xFFB6   1   no   ivVcan0wkup   unused by PE */
  Cpu_Interrupt,                        /* 0x5C  0xFFB8   1   no   ivVflash      unused by PE */
  Cpu_Interrupt,                        /* 0x5D  0xFFBA   1   no   ivVeeprom     unused by PE */
  Cpu_Interrupt,                        /* 0x5E  0xFFBC   1   no   ivVspi2       unused by PE */
  Cpu_Interrupt,                        /* 0x5F  0xFFBE   1   no   ivVspi1       unused by PE */
  Cpu_Interrupt,                        /* 0x60  0xFFC0   1   no   ivViic0       unused by PE */
  Cpu_Interrupt,                        /* 0x61  0xFFC2   1   no   ivVReserved30 unused by PE */
  Cpu_Interrupt,                        /* 0x62  0xFFC4   1   no   ivVcrgscm     unused by PE */
  Cpu_Interrupt,                        /* 0x63  0xFFC6   1   no   ivVcrgplllck  unused by PE */
  Cpu_Interrupt,                        /* 0x64  0xFFC8   1   no   ivVtimpabovf  unused by PE */
  Cpu_Interrupt,                        /* 0x65  0xFFCA   1   no   ivVtimmdcu    unused by PE */
  Cpu_Interrupt,                        /* 0x66  0xFFCC   1   no   ivVporth      unused by PE */
  Cpu_Interrupt,                        /* 0x67  0xFFCE   1   no   ivVportj      unused by PE */
  Cpu_Interrupt,                        /* 0x68  0xFFD0   1   no   ivVatd1       unused by PE */
  Cpu_Interrupt,                        /* 0x69  0xFFD2   1   no   ivVatd0       unused by PE */
  Cpu_Interrupt,                        /* 0x6A  0xFFD4   1   no   ivVsci1       unused by PE */
  Cpu_Interrupt,                        /* 0x6B  0xFFD6   1   no   ivVsci0       unused by PE */
  Cpu_Interrupt,                        /* 0x6C  0xFFD8   1   no   ivVspi0       unused by PE */
  Cpu_Interrupt,                        /* 0x6D  0xFFDA   1   no   ivVtimpaie    unused by PE */
  Cpu_Interrupt,                        /* 0x6E  0xFFDC   1   no   ivVtimpaaovf  unused by PE */
  Cpu_Interrupt,                        /* 0x6F  0xFFDE   1   no   ivVtimovf     unused by PE */
  Cpu_Interrupt,                        /* 0x70  0xFFE0   1   no   ivVtimch7     unused by PE */
  Cpu_Interrupt,                        /* 0x71  0xFFE2   1   no   ivVtimch6     unused by PE */
  Cpu_Interrupt,                        /* 0x72  0xFFE4   1   no   ivVtimch5     unused by PE */
  Cpu_Interrupt,                        /* 0x73  0xFFE6   1   no   ivVtimch4     unused by PE */
  Cpu_Interrupt,                        /* 0x74  0xFFE8   1   no   ivVtimch3     unused by PE */
  Cpu_Interrupt,                        /* 0x75  0xFFEA   1   no   ivVtimch2     unused by PE */
  Cpu_Interrupt,                        /* 0x76  0xFFEC   1   no   ivVtimch1     unused by PE */
  Cpu_Interrupt,                        /* 0x77  0xFFEE   1   no   ivVtimch0     unused by PE */
  Cpu_Interrupt,                        /* 0x78  0xFFF0   1   no   ivVrti        unused by PE */
  Cpu_Interrupt,                        /* 0x79  0xFFF2   1   no   ivVirq        unused by PE */
  Cpu_Interrupt,                        /* 0x7A  0xFFF4   -   -    ivVxirq       unused by PE */
  Cpu_Interrupt,                        /* 0x7B  0xFFF6   -   -    ivVswi        unused by PE */
  Cpu_Interrupt                         /* 0x7C  0xFFF8   -   -    ivVtrap       unused by PE */
};

const tIsrFunc _ResetVectorTable[] @0xFFFA = { /* Reset vector table */
  /* Reset handler name                    Address Name           Description */
  _EntryPoint,                          /* 0xFFFA  ivVcop         unused by PE */
  _EntryPoint,                          /* 0xFFFC  ivVclkmon      unused by PE */
  _EntryPoint                           /* 0xFFFE  ivVreset       used by PE */
};
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
