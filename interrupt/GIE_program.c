#include "STDTYPE.h"
#include "UTILS.h"
#include "GIE_private.h"
#include "GIE_interface.h"

/*GIE Enable */
void GIE_Enable (void){
SET_BIT(SREG ,SREG_I_BIT);	
	
}

/*GIE Disable */
void GIE_Disable (void){
	
	CLR_BIT(SREG ,SREG_I_BIT);
}