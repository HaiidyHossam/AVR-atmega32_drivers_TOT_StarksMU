/*
 * UART_private.h
 *
 * Created: 6/27/2023 7:00:46 PM
 *  Author: HAIIDY HOSSAM
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR    *((volatile u8 *) 0x2C) /* TX data register share the same I/O bus with RX data register */
#define UCSRA  *((volatile u8 *) 0x2B)
#define UCSRB  *((volatile u8 *) 0x2A)
#define UCSRC  *((volatile u8 *) 0x40) /* share the same address with UBRRH */
#define UBRRL  *((volatile u8 *) 0x29)
#define UBRRH  *((volatile u8 *) 0x40)

#define UCSRA_RXC      7
#define UCSRA_TXC      6
#define UCSRA_UDRE     5
#define UCSRA_FE       4
#define UCSRA_DOR      3
#define UCSRA_PE       2
#define UCSRA_U2X      1
#define UCSRA_MPCM     0

#define UCSRB_RXCIE    7
#define UCSRB_TXCIE    6
#define UCSRB_UDRIE    5
#define UCSRB_RXEN     4
#define UCSRB_TXEN     3
#define UCSRB_UCSZ2    2
#define UCSRB_RXB8     1
#define UCSRB_TXB8     0

#define UCSRC_URSEL    7
#define UCSRC_UMSEL    6
#define UCSRC_UPM1     5
#define UCSRC_UPM0     4
#define UCSRC_USBS     3
#define UCSRC_UCSZ1    2
#define UCSRC_UCSZ0    1
#define UCSRC_UCPOL    0

#define UBRRL_URSEL    7
#define UBRRL_UBRR_11  3
#define UBRRL_UBRR_10  2
#define UBRRL_UBRR_9   1
#define UBRRL_UBRR_8   0 




#endif /* UART_PRIVATE_H_ */