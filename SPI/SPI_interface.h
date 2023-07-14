/*
 * SPI_interface.h
 *
 * Created: 7/13/2023 7:50:30 PM
 *  Author:Haiidy Hossam
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_INIT_MASTER (void);
void SPI_INIT_SLAVE (void);
//SPI normally sends and receives at the same time
u8 SPI_TR_RC (u8 data);





#endif /* SPI_INTERFACE_H_ */