/*
 * SPI_private.h
 *
 * Created: 7/13/2023 7:50:53 PM
 *  Author: Haiidy Hossam
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR  *((volatile u8 *) 0x2D)
#define SPSR  *((volatile u8 *) 0x2E)
#define SPDR  *((volatile u8 *) 0x2F)
/*  SPCR pins */
#define SPCR_SPIE_PIN    7
#define SPCR_SPE_PIN     6
#define SPCR_DORD_PIN    5
#define SPCR_MSTR_PIN    4
#define SPCR_CPOL_PIN    3
#define SPCR_CPHA_PIN    2
#define SPCR_SPR1_PIN    1
#define SPCR_SPR0_PIN    0
/*  SPSR pins */
#define SPSR_SPIF        7
#define SPSR_WCOL        6
#define SPSR_SPI2X       0



#endif /* SPI_PRIVATE_H_ */