/*
 * ADC_program.c
 *
 * Created: 2/26/2023 5:33:47 PM
 *  Author: Haiidy Hossam
 */ 
#include "STDTYPE.h"
#include "UTILS.h"
#include "ADC_interface.h"


void ADC_init(){
// select Vref
SET_BIT(ADMUX,6);
CLR_BIT(ADMUX,7);
//Select prescaler
SET_BIT(ADCSRA,0);
SET_BIT(ADCSRA,1);
SET_BIT(ADCSRA,2);
//select adjust
SET_BIT(ADMUX,5);
//enable ADC
SET_BIT(ADCSRA,7);	
}

u8 ADC_Read(u8 channel){ //0b00001
	//select channel
	ADMUX &=0b11100000;
	
	ADMUX=ADMUX | channel;
	
	//start conversion
	SET_BIT(ADCSRA,6);
	
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4);
	
	return ADCH;
	
	
	
}