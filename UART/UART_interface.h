/*
 * UART_interface.h
 *
 * Created: 6/27/2023 7:00:25 PM
 *  Author: HAIIDY HOSSAM
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_INIT(void);
void UART_SEND (u8 data);
u8 UART_RECEIVE (void);
u8 UART_RECInterrupt (void (*func)(void), u8 *DataPtr);
void UART_SEND_String (u8 array[]);
void UART_RECEIVE_String (u8 * array);



#endif /* UART_INTERFACE_H_ */