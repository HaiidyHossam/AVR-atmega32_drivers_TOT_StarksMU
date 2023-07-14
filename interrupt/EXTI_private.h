#ifndef  EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*sesnse control reg INT0-INT1 */

#define MCUCR *((volatile u8 *)0x55)
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3
/*sesnse control reg INT2*/


//interrupt 2
#define MCUCSR *((volatile u8*)0x54)
#define MCUCSR_ISC2_PIN 6

/*enable interrupt control register*/
#define GICR  *((volatile u8*)0x5B)
#define GICR_INT2_PIN 5
#define GICR_INT0_PIN 6
#define GICR_INT1_PIN 7

/*exti flag register*/
#define GIFR  *((volatile u8*)0x5A)
#define GIFR_INTF1_PIN 7
#define GIFR_INTF0_PIN 6
#define GIFR_INTF2_PIN 5




#endif