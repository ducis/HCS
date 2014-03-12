/** ###################################################################
**     Filename  : VehicleStats.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-13, 16:48
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

#ifndef __VehicleStats_H
#define __VehicleStats_H
#include "Marco.h"
/* MODULE VehicleStats */

/*************************************************************
                     *START OF DECLARATION*
**************************************************************/
int timer=0;
int timer1;
int stop_time=0;
int stop_distance;
int waitstart=0;
unsigned char start_line;
unsigned char his_flag=0;
int center=100;

unsigned char sw[4];

/*************************************************************
                     *DECLARATION OF SIGN_DISTINGUISH*
**************************************************************/
unsigned char pos_symbol,sgn,sgn1,a1,a2,a3;
unsigned char pos_symbol1;
unsigned char pos_symbol2;
unsigned char k1,k,switch1,k2,switch_ok,mark_diuxian1,mark_diuxian2,mark_wait;

unsigned char pos_tem,mile;
unsigned int milemeter,old_mile,old_mile1,old_mile2,old_mile3;       
unsigned char count_up1;
unsigned int count_up2; 
unsigned char count_up3;     //����
unsigned char post[SECONDROW];
char temper;
unsigned char start_line_count=0;
unsigned char start_line_flag;
unsigned int start_line_temp;//��¼������ʼ��ʱ����ʱ����������һ�μ��

/*************************************************************
                     *DECLARATION OF SPEED*
**************************************************************/
unsigned char velocity[4];   //fastest

int target_v;
int current_v;
unsigned char his_v[10];
int sum_v;


/*************************************************************
                     *DECLARATION OF PID*
**************************************************************/
unsigned char K[5];

/*************************************************************
                     *DECLARATION OF TWO ROWS*
**************************************************************/

unsigned char his_normal[8];
unsigned char tri_sign_temp;
unsigned char his_B_num;


unsigned char filter1[FIRSTROW];
unsigned char filter[SECONDROW];
unsigned char overflow_count1,overflow_count2,guopo,sgn_guopo[3];  
unsigned int overflow1,guopo_count;

unsigned char startline_count;
unsigned char first_lost;
unsigned char line1_sign=0; //0: ������ ��1:���º����µ�ת�۵� 2���¶�ת��˲�� ��ʮ���� 3����ʼ��
unsigned char line1_sign_temp;
unsigned char line1_sign_distance;
unsigned char line2_sign=0; //0: ������ ��1:���º����µ�ת�۵� 2���¶�ת��˲�� ��ʮ���� 3����ʼ��
unsigned char last1_sign=0; //��¼��һ�ŵĴ����µ�������ɵ�״̬�� 
unsigned int distance;    //��¼����
unsigned int distance_ramp;//�µ���
unsigned char count_flag; //�������Ĵ���

/*************************************************************
                     *DECLARATION OF STEER*
**************************************************************/
int current_steer1=STEER1_CENTER;
int his_steer1[10];
int current_steer2=STEER2_CENTER;
int his_steer2[10];
unsigned char steer2_flag;//���ƶ��2�Ƿ���Խ����´��涯�����ǵ������Ҫʱ��ȥ��ת
unsigned char steer2_time_flag;

/*************************************************************
*DECLARATION OF 1st AND 2nd ORDER DIFFERENCE*
**************************************************************/
char first_diff[10];
char second_diff[10];

unsigned char Car_state;
unsigned char test;
 /*************************************************************
*DECLARATION OF speed adjust*
**************************************************************/
unsigned int ye;
unsigned char fasudu;
unsigned char sudubiaoding[1000];
unsigned int qw;

/* END VehicleStats */

#endif
