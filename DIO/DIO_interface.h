/*
 * DIO_interface.h
 *
 * Created: 2/12/2023 2:41:30 PM
 *  Author: Haiidy Hossam
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum{
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	Pin_0=0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7,
	LOW=0,
	HIGH,
	input=0,
	output,
	Port_HIGH=255 ,
	Port_LOW=0x00,
	Port_output=0xff,
	Port_input=0x00
	}en; 


void DIO_SetPinValue(u8 port,u8 pin_num,u8 Value);
void DIO_SetPinDirection(u8 port,u8 pin_num,u8 Direction);
u8 DIO_GetPinValue(u8 port,u8 pin_num);

void DIO_SetPortValue(u8 port, u8 Value); 
void DIO_SetPortDirection(u8 port, u8 Direction); //255 == 0b11100111
void DIO_GetPortValue(u8 port, u8 *value);




#endif /* DIO_INTERFACE_H_ */