/*
 * Timer0_private.h
 *
 * Created: 9/26/2023 3:39:20 PM
 *  Author: youssef
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define TCNTO_Reg  *((volatile u8 *)0x52)
#define TCCR0_Reg  *((volatile u8 *)0x53)
#define TIFR_Reg   *((volatile u8 *)0x58)
#define TIMSK_Reg  *((volatile u8 *)0x59)
#define OCR0_Reg   *((volatile u8 *)0x5c)


#endif /* TIMER0_PRIVATE_H_ */