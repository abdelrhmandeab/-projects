#ifndef   INTERRUPT_VECTOR_H_
#define   INTERRUPT_VECTOR_H_

#define  ISR(__vector_NUM)  void __vector_NUM(void)__attribute__((signal)) ;\
                             void __vector_NUM(void)

#define  INT_0_          __vector_1 
#define  INT_1_          __vector_2
#define  INT_2_          __vector_3
#define  TIMER2_COMP     __vector_4
#define  TIMER2_OVF      __vector_5
#define  TIMER1_COMPA    __vector_6
#define  TIMER1_COMPB    __vector_7
#define  TIMER1_OVF      __vector_8
#define  TIMER0_COMP     __vector_10
#define  TIMER0_OVF      __vector_11
#define  ADC		     __vector_16

#endif 