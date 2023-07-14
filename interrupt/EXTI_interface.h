#ifndef  EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*EXTI ENABLE */
#define LOW_LEVEl 0
#define falling_edge 1
#define rising_edge 2
#define on_change 3

#define Sense_Control rising_edge

//______________
void GIE_enable(void);
void GIE_disable(void);
void INT_0_init();
void INT_1_init();
void INT_2_init();
void INT0_CallBack(void (*func)(void));
void INT1_CallBack(void (*func)(void));
void INT2_CallBack(void (*func)(void));




#endif