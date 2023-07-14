/*
 * TimerZero.c
 *
 * Created: 3/8/2023 1:42:25 PM
 *  Author: Haiidy Hossam
 */ 
#include "STDTYPE.h"
#include "UTILS.h"
#include "Timer0_interface.h"

void GIE_enable(void){
	SET_BIT(SREG,7);
}
void GIE_disable(void){
	CLR_BIT(SREG,7);
}
void Timer0_OverFlow_init(u8 prescaler , u8 preload){
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	TCNT0=preload;
	SET_BIT(TIMSK,0);
	
	if(prescaler==8){
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(prescaler==64){
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
}

void (*ptr_T0_overflow)(void);
void over_flow_call(void(*func)(void)){
	ptr_T0_overflow=func;
}
void __vector_11(void)__attribute((signal));
void __vector_11(void){
	ptr_T0_overflow();
	//toggle
}

void Timer0_CTC_init(u8 prescaler, u8 OCR_value){
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	OCR0=OCR_value;
	SET_BIT(TIMSK,1);
		if(prescaler==8){
			CLR_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
		else if(prescaler==64){
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
}
void (*ptr_T0_CTC)(void);
void CTC_call(void(*func)(void)){
	ptr_T0_CTC=func;
}
void __vector_10(void)__attribute((signal));
void __vector_10(void){
	ptr_T0_CTC();
	//toggle
}