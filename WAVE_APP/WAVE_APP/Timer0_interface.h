/*
 * Timer0_interface.h
 *
 * Created: 9/26/2023 3:39:39 PM
 *  Author: youssef
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



 /*SELECT MODE*/

 #define CTC_MODE  1
 #define OVF_MODE  2
 
void Timer0_Vid_Delayms(u16 copy_u8_timems);
void Timer0_Vid_Delayus(f64 copy_u8_timeus);
void Timer0_Vid_Init(u8 copy_u8_mode);
void TIME0_Vid_SetCallBack(u8 copy_u8_mode, void (*ptr_fun)(void));
void TIMER0_VID_Fast_PWM(u8 copy_u8_DutyCycle);


#define DIVISION0      0x00
#define DIVISION1      0x01
#define DIVISION8      0x02
#define DIVISION64     0x03
#define DIVISION256    0x04
#define DIVISION1024   0x05

#define WGM00_PIN    6
#define WGM01_PIN	 3


#define CS00_PIN     0
#define CS01_PIN     1
#define CS02_PIN     2

#define TOIE0        0 // Timer/Counter0 Overflow Interrupt Enable
#define OCIE0		 1 // Timer/Counter0 CTC Interrupt Enable

#define TOV0		 0 // Timer/Counter0 Overflow Flag
#define OCF0		 1

#define Prescalerms    DIVISION64
#define Prescalerus	   DIVISION1

#define OCR0_VAL  250

#define COM00_PIN 4
#define COM01_PIN 5




#endif /* TIMER0_INTERFACE_H_ */