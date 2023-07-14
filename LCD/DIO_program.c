#include "STDTYPE.h"
#include "UTILS.h"
#include "DIO_private.h"
#include "DIO_interface.h"

void DIO_SetPinValue(u8 port, u8 pin_num,u8 Value){
	if(Value==HIGH){
		switch(port){
			case Port_A:
			SET_BIT(PORTA,pin_num);
			break;
			case Port_B:
			SET_BIT(PORTB,pin_num);
			break;
			case Port_C:
			SET_BIT(PORTC,pin_num);
			break;
			case Port_D:
			SET_BIT(PORTD,pin_num);
			break;
			
		}
	}
		else if(Value==LOW){
			switch(port){
				case Port_A:
				CLR_BIT(PORTA,pin_num);
				break;
				case Port_B:
				CLR_BIT(PORTB,pin_num);
				break;
				case Port_C:
				CLR_BIT(PORTC,pin_num);
				break;
				case Port_D:
				CLR_BIT(PORTD,pin_num);
				break;
				
			}
			
		}
	
	
}

void DIO_SetPinDirection(u8 port, u8 pin_num,u8 Direction){
	
	if(Direction==input){
		switch(port){
			case Port_A:
			CLR_BIT(DDRA,pin_num);
			break;
			case Port_B:
			CLR_BIT(DDRB,pin_num);
			break;
			case Port_C:
			CLR_BIT(DDRC,pin_num);
			break;
			case Port_D:
			CLR_BIT(DDRD,pin_num);
			break;
		}
	}
	else if(Direction==output){
		switch(port){
			case Port_A:
			SET_BIT(DDRA,pin_num);
			break;
			case Port_B:
			SET_BIT(DDRB,pin_num);
			break;
			case Port_C:
			SET_BIT(DDRC,pin_num);
			break;
			case Port_D:
			SET_BIT(DDRD,pin_num);
			break;
		}
		
	}
}
void DIO_GetPinValue(u8 port, u8 pin_num,u8 *value){
	switch (port){
		case Port_A:
		*value=GET_BIT(PINA,pin_num);
		break;
		case Port_B:
		*value=GET_BIT(PINB,pin_num);
		break;
		case Port_C:
		*value=GET_BIT(PINC,pin_num);
		break;
		case Port_D:
		*value=GET_BIT(PIND,pin_num);
		break;
	}
	
}
void DIO_SetPortValue(u8 port, u8 value){
	switch (port)
	{
		case Port_A: //1 == 0b0000 0001
		PORTA=value; //0b1111 1001
		break;
		case Port_B:
		PORTB=value;
		break;
		case Port_C:
		PORTC=value;
		break;
		case Port_D:
		PORTD=value;
		break;
	}
}
void DIO_SetPortDirection(u8 port, u8 Direction){
	switch(port){
		case Port_A:
		DDRA=Direction;
		break;
		case Port_B:
		DDRB=Direction;
		break;
		case Port_C:
		DDRC=Direction;
		break;
		case Port_D:
		DDRD=Direction;
		break;
		
	}
}
void DIO_GetPortValue(u8 port, u8 *value){
	switch(port){
		case Port_A: {
		*value=PINA;
		break;}
		case Port_B:
		*value=PINB;
		break;
    	case Port_C:
		*value=PINC;
		break;
		case Port_D:
		*value=PIND;
		break;
		
	}
	
}