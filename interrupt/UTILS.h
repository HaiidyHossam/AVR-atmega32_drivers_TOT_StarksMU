

#ifndef UTILS_H_
#define UTILS_H_


#define NULL 0

#define SET_BIT(BYTE,Bit_NO) (BYTE |= (1<<(Bit_NO)))
#define CLR_BIT(BYTE,Bit_NO) (BYTE &= ~(1<<(Bit_NO)))
#define GET_BIT(BYTE,Bit_NO) ((BYTE >> Bit_NO) & 1)
#define TOGGLE_BIT(BYTE,Bit_NO) BYTE ^=(1<<(Bit_NO))


#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD (*(volatile unsigned char*)0x31)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTC (*(volatile unsigned char *) 0x35)
#define DDRC (*(volatile unsigned char *) 0x34)
#define PINC (*(volatile unsigned char *) 0x33)

#define DDRB (*(volatile unsigned char *) 0x37)
#define PORTB (*(volatile unsigned char *) 0x38)
#define PINB (*(volatile unsigned char *) 0x36)




#endif /* UTILS_H_ */