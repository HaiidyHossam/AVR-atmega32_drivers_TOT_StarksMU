#include "STDTYPE.h"
#include "UTILS.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


void INT_0_init(){
	if(Sense_Control==LOW_LEVEl){
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Sense_Control==falling_edge){
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Sense_Control==rising_edge){
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Sense_Control==on_change){
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	SET_BIT(GICR,GICR_INT0_PIN);
}

void INT_1_init(){
	if(Sense_Control==LOW_LEVEl){
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Sense_Control==falling_edge){
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Sense_Control==rising_edge){
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Sense_Control==on_change){
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	SET_BIT(GICR,GICR_INT1_PIN);
}

void INT_2_init(){
	if(Sense_Control==rising_edge){
		SET_BIT(MCUCSR,MCUCSR_ISC2_PIN);
	}
	else if(Sense_Control==falling_edge){
		CLR_BIT(MCUCSR,MCUCSR_ISC2_PIN);
	}
	SET_BIT(GICR,GICR_INT2_PIN);
}

void (*INT0_ISR) (void)=NULL;
void (*INT1_ISR) (void)=NULL;
void (*INT2_ISR) (void)=NULL;

void INT0_CallBack(void (*func)(void)){
	if(func!=NULL){
		INT0_ISR=func;
	}
}

void INT2_CallBack(void (*func)(void)){
	if(func!=NULL){
		INT2_ISR=func;
	}
}
void INT1_CallBack(void (*func)(void)){
	if(func!=NULL){
		INT1_ISR=func;
	}
}

void __vector_1 (void)__attribute__((signal));
void __vector_1(void){
	INT0_ISR();
}
void __vector_2 (void)__attribute__((signal));
void __vector_2(void){
	INT1_ISR();
}
void __vector_3 (void)__attribute__((signal));
void __vector_3(void){
	INT2_ISR();
}
