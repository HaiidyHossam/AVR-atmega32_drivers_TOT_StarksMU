#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

#include "STDTYPE.h"
typedef enum{
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	Pin_0 =0,
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
	Port_HIGH=0xff,
Port_LOW=0x00,
Port_OUTPUT=0xff,
Port_INPUT=0x00
	

	
	}en;



void DIO_SetPinValue(u8 port, u8 pin_num,u8 Value);
void DIO_SetPinDirection(u8 port, u8 pin_num,u8 Direction);
void DIO_GetPinValue(u8 port, u8 pin_num,u8 *value);

void DIO_SetPortValue(u8 port, u8 value);
void DIO_SetPortDirection(u8 port, u8 Direction);
void DIO_GetPortValue(u8 port, u8 *value);



#endif