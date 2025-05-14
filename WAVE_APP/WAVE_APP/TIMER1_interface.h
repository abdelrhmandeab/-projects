/*
 * TIMER1_interface.h
 *
 * Created: 10/3/2023 12:45:38 AM
 *  Author: youssef
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER_Vid_FastPWM_ICR1_Init(void);
void TIMER1_Vid_SetCompareVal(u32 copy_u32_val);
void TIMER1_VID_Fast_PWM(u8 copy_u8_Duty);
void TIMER1_Vid_NormalMode_Init();
void TIMER1_Vid_Reset_Timer();
u32  TIMER1_u32_ReadVal();

/*TCCRA1*/
#define WGM10_PIN 0
#define WGM11_PIN 1
#define COM1B0_PIN 4
#define COM1B1_PIN 5
#define COM1A0_PIN 6
#define COM1A1_PIN 7
/*TCCRB1*/
#define WGM12_PIN 3
#define WGM13_PIN 4

/*PRESCALER PINS*/
#define CS10_PIN  0
#define CS11_PIN  1
#define CS12_PIN  2
/*TIMSK PINS*/
#define TOIE1_PIN 2
#define OCIE1B_PIN 3
#define OCIE1A_PIN 4
#define TICIE1_PIN 5
/*TIFR PINS*/
#define OCF1A_PIN  4



#define DIVISION0      0x00
#define DIVISION1      0x01
#define DIVISION8      0x02
#define DIVISION64     0x03
#define DIVISION256    0x04
#define DIVISION1024   0x05

#define Prescalerms    DIVISION64
#define Prescalerus	   DIVISION1


#endif /* TIMER1_INTERFACE_H_ */