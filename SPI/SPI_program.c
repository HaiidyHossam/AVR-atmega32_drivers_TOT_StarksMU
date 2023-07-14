/*
 * SPI_program.c
 *
 * Created: 7/13/2023 7:51:49 PM
 *  Author: Haiidy Hossam
 */ 
#include "STDTYPE.h"
#include "UTILS.h"
#include "SPI_interface.h"
#include "SPI_private.h"

void SPI_INIT_MASTER (void){
	//disable interrupt
	CLR_BIT(SPCR,SPCR_SPIE_PIN);
	
	//MSB 
	CLR_BIT(SPCR,SPCR_DORD_PIN);
	
	//master SS
	SET_BIT(SPCR,SPCR_MSTR_PIN);
	
	//polarity >> leading edge is rising
	CLR_BIT(SPCR,SPCR_CPOL_PIN);
	
	//Sample at leading edge >> sample= receive
	CLR_BIT(SPCR,SPCR_CPHA_PIN);
	
	
	// freq 16 -- master decides the clock
	SET_BIT(SPCR,SPCR_SPR0_PIN);
	CLR_BIT(SPCR,SPCR_SPR1_PIN);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE_PIN);
}
void SPI_INIT_SLAVE (void){
	//disable interrupt
	CLR_BIT(SPCR,SPCR_SPIE_PIN);
	
	//MSB
	CLR_BIT(SPCR,SPCR_DORD_PIN);
	
	//master SS
	CLR_BIT(SPCR,SPCR_MSTR_PIN);
	
	//polarity >> leading edge is rising
	CLR_BIT(SPCR,SPCR_CPOL_PIN);
	
	//Sample at leading edge >> sample= receive
	CLR_BIT(SPCR,SPCR_CPHA_PIN);
	
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE_PIN);
}

u8 SPI_TR_RC (u8 data){
	//send data
	SPDR=data;
	//wait till data is sent
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	//return received data
	return SPDR;
	
}