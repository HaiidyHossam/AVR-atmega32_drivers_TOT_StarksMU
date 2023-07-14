#include "STDTYPE.h"
#include "DIO_interface.h"
#include "LCD_Config.h"
#include "avr/delay.h"


void LCD_Send_Command (u8 command){
	/* set RS as LOW */
	DIO_SetPinValue(CTRL_PORT,RS_Pin,LOW);
	/* set RW as LOW to Write */
	DIO_SetPinValue(CTRL_PORT,RW_Pin,LOW);
	
	// send command to data port
	DIO_SetPortValue(Data_Port,command);
	
	//set enable pulse 
	DIO_SetPinValue(CTRL_PORT,Enable_Pin,HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CTRL_PORT,Enable_Pin,LOW);
	
	
	
}
void LCD_Send_Data (u8 Data){
	/* set RS as HIGH */
	DIO_SetPinValue(CTRL_PORT,RS_Pin,HIGH);
	/* set RW as LOW to Write */
	DIO_SetPinValue(CTRL_PORT,RW_Pin,LOW);
	
	//send data to data port
	DIO_SetPortValue(Data_Port,Data);
	//set enable pulse
	DIO_SetPinValue(CTRL_PORT,Enable_Pin,HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CTRL_PORT,Enable_Pin,LOW);
	
	
}
void LCD_Init(void){
	
	_delay_ms(40);
	
	//function set 
	LCD_Send_Command (0b00111111);
	
	_delay_ms(40);
	
	//On-off
	LCD_Send_Command (0b00001100);
	_delay_ms(40);
	
	//clear
	LCD_Send_Command (0b00000001);
	_delay_ms(2);
	
	//entry set mode
	LCD_Send_Command(0b00000110);
	_delay_ms(40);
	
	
}
void GOTOXY(u8 x,u8 y){ //(1,4)
	u8 address=0;
	if(x==0){
		address=y;
	}
	else if(x==1){
		address=0x40+y; //44=0b01000100
	}
	//DDram address = 0b10000000 //80
	LCD_Send_Command(0b10000000+address);
	
}

void LCD_Clear(){
	LCD_Send_Command(0b00000001);
	_delay_ms(2);
	LCD_Send_Command(0b10000000);
}



void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Send_Data(str[i]);
	}
}