/*
 * TIMER1_private.h
 *
 * Created: 10/3/2023 12:46:37 AM
 *  Author: youssef
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TIMSK_Reg		*((volatile u8 *)0x59)
#define TIFR_Reg		*((volatile u8 *)0x58)
#define TCCR1A_Reg		*((volatile u8 *)0x4F)
#define TCCR1B_Reg		*((volatile u8 *)0x4E)
#define TCNT1_Reg		*((volatile u16 *)0x4C)
#define OCR1A_Reg		*((volatile u16 *)0x4A)
#define OCR1B_Reg		*((volatile u16 *)0x48)
#define ICR1_Reg		*((volatile u16 *)0x46)




#endif /* TIMER1_PRIVATE_H_ */