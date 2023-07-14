/*
 * Timer0_interface.h
 *
 * Created: 3/8/2023 1:42:52 PM
 *  Author: Haiidy Hossam
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#define  TCCR0   *((volatile u8 *)0x53)
#define  TCNT0   *((volatile u8 *)0x52)
#define  TIMSK     *((volatile u8 *)0x59)

#define SREG *((volatile u8*)0x5f)

#define OCR0 *((volatile u8 *) 0x5C)

void Timer0_OverFlow_init(u8 prescaler , u8 preload);
void GIE_enable(void);
void GIE_disable(void);
void over_flow_call(void(*func)(void));

void Timer0_CTC_init(u8 prescaler, u8 OCR_value);
void CTC_call(void(*func)(void));



#endif /* TIMER0_INTERFACE_H_ */