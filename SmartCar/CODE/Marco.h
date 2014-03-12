/** ###################################################################
**     Filename  : Marco.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-13, 19:31
**     Contents  :
**         User source code
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __Marco_H
#define __Marco_H

/* MODULE Marco */

#define   FIRSTROW                  8
#define   SECONDROW                 6
#define   STEER1_CENTER           3125
#define   STEER1_RIGHT            3650
#define   STEER1_LEFT             2600
#define   STEER2_LEFT             3380
#define   STEER2_CENTER           3030
#define   STEER2_RIGHT            2680
#define   STEER2_TIME_FLAG        15  //��ʱ60ms����һ���涯
#define   STEER2_CON_ON           0x01     //��һ���涯����
#define   STEER2_CON_OFF          0x00     //��һ���涯��ֹ

/* END Marco */

#endif
