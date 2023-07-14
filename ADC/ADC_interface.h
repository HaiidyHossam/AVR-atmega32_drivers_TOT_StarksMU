/*
 * ADC_interface.h
 *
 * Created: 2/26/2023 5:34:06 PM
 *  Author: Haiidy Hossam
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADMUX (*(volatile u8 *) 0x27)

#define ADCSRA (*(volatile u8 *) 0x26)

#define ADCH (*(volatile u8 *) 0x25)

void ADC_init();
u8 ADC_Read(u8 channel);



#endif /* ADC_INTERFACE_H_ */