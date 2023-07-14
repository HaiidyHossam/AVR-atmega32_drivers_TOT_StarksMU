

#ifndef UTILS_H_
#define UTILS_H_

#define NULL 0
#define SET_BIT(BYTE,Bit_NO) (BYTE |= (1<<(Bit_NO)))
#define CLR_BIT(BYTE,Bit_NO) (BYTE &= ~(1<<(Bit_NO)))
#define GET_BIT(BYTE,Bit_NO) ((BYTE >> Bit_NO) & 1)
#define TOGGLE_BIT(BYTE,Bit_NO) BYTE ^=(1<<(Bit_NO))





#endif /* UTILS_H_ */
