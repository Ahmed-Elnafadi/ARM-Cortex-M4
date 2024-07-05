/********************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------------------------------------------------------*/
/**			\file SCC_Ctrl.c

 *          \brief System Control and Clock
 *
 *			\details Driver configure clock of system and clock to each peripheral and reset of the system
 *                   
 *
 *******************************************************************************************************************************/
 
/*******************************************************************************************************************************
 * INCLUDES
 ******************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SCC_Ctrl.h"
#include "SCC_Hw.h"
#include "SCC_Types.h"
#include "SCC_Cfg.h"

/*******************************************************************************************************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 ******************************************************************************************************************************/
  

/*******************************************************************************************************************************
 * LOCAL DATA
 ******************************************************************************************************************************/


/*******************************************************************************************************************************
 * GLOBAL DATA
 ******************************************************************************************************************************/


/*******************************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ******************************************************************************************************************************/


/*******************************************************************************************************************************
 * LOCAL FUNCTIONS
 ******************************************************************************************************************************/
  
  
/*******************************************************************************************************************************
 * GLOBAL FUNCTIONS
 ******************************************************************************************************************************/

/*******************************************************************************************************************************
 * \Syntax			: void SCC_Init(void)
 * \Description     : Set peripheral clock
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : None
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
 void SCC_Init(void){
	
	/* Implement Code */
	/* Main Oscillator */
	#if MAIN_OSCILLATOR == DISABLE
	SET_BIT(RCC, MOSCDIS);
	
	#elif MAIN_OSCILLATOR == ENABLE
	CLR_BIT(RCC, MOSCDIS);
	
	#else
		#error "Wrong Input"
	
	#endif
	
	/* Oscillator Source */
	
	#if OSCILLATOR_SOURCE == MAIN_OSCILL
	CLR_BIT(RCC, OSCSRC_4);
	CLR_BIT(RCC, OSCSRC_5);
	
	#elif OSCILLATOR_SOURCE == PRECISION_INTERNAL_OSCILLATOR
	SET_BIT(RCC, OSCSRC_4);
	CLR_BIT(RCC, OSCSRC_5);
	
	#elif OSCILLATOR_SOURCE == PIOSC_DIV_4
	CLR_BIT(RCC, OSCSRC_4);
	SET_BIT(RCC, OSCSRC_5);
	
	#elif OSCILLATOR_SOURCE == LFIOSC
	SET_BIT(RCC, OSCSRC_4);
	SET_BIT(RCC, OSCSRC_5);
	
	#else
		#error "Wrong Input"
	
	#endif
	
	/* Enable GPIO_A Clock */
	SCC_SetClockPeripheral(GPIO_A, ENABLE);
	
	/* (Polling) Waiting until GPIO_A Ready to access */
	while(SCC_PeripheralReady(GPIO_A) != 1);
}


/*******************************************************************************************************************************
 * \Syntax			: Static void SCC_SetClockPeripheral(Peripheral_t copy_Peripheral, uint8_t copy_State)
 * \Description     : Set peripheral clock
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Peripheral Name, State (Enable, Disable)
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void SCC_SetClockPeripheral(Peripheral_t copy_Peripheral, uint8_t copy_State){
	
	/* Implement Code */
	if(copy_State == ENABLE){
		if(copy_Peripheral == GPIO_A){
			SET_BIT(RCGCGPIO, GPIO_A_RC);
		}
		else if(copy_Peripheral == GPIO_B){
			SET_BIT(RCGCGPIO, GPIO_B_RC);
		}
		else if(copy_Peripheral == GPIO_C){
			SET_BIT(RCGCGPIO, GPIO_C_RC);
		}
		else if(copy_Peripheral == GPIO_D){
			SET_BIT(RCGCGPIO, GPIO_D_RC);
		}
		else if(copy_Peripheral == GPIO_E){
			SET_BIT(RCGCGPIO, GPIO_E_RC);
		}
		else if(copy_Peripheral == GPIO_F){
			SET_BIT(RCGCGPIO, GPIO_F_RC);
		}
		else{
			/* wrong configurion input */
		}
	}
	else if(copy_State == DISABLE){
		if(copy_Peripheral == GPIO_A){
			CLR_BIT(RCGCGPIO, GPIO_A_RC);
		}
		else if(copy_Peripheral == GPIO_B){
			CLR_BIT(RCGCGPIO, GPIO_B_RC);
		}
		else if(copy_Peripheral == GPIO_C){
			CLR_BIT(RCGCGPIO, GPIO_C_RC);
		}
		else if(copy_Peripheral == GPIO_D){
			CLR_BIT(RCGCGPIO, GPIO_D_RC);
		}
		else if(copy_Peripheral == GPIO_E){
			CLR_BIT(RCGCGPIO, GPIO_E_RC);
		}
		else if(copy_Peripheral == GPIO_F){
			CLR_BIT(RCGCGPIO, GPIO_F_RC);
		}
		else{
			/* wrong configurion input */
		}	
		
	}
	else{
		/* wrong configurion input */
	}
	
}

/*******************************************************************************************************************************
 * \Syntax			: Static void SCC_PeripheralReady(Peripheral_t copy_Peripheral)
 * \Description     : Check peripheral clock is ready for access
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Peripheral Name
 * \parameters (out): Ready, not Ready
 * \Return Value    : uint8_t
 *******************************************************************************************************************************/
static uint8_t SCC_PeripheralReady(Peripheral_t copy_Peripheral){
	
	
	/* Implement Code */
	
	uint8_t state =0;
	
	if(copy_Peripheral == GPIO_A){
		state = GET_BIT(PRGPIO, GPIO_A_RC);
	}
	else if(copy_Peripheral == GPIO_B){
		state = GET_BIT(PRGPIO, GPIO_B_RC);
	}
	else if(copy_Peripheral == GPIO_C){
		state = GET_BIT(PRGPIO, GPIO_C_RC);
	}
	else if(copy_Peripheral == GPIO_D){
		state = GET_BIT(PRGPIO, GPIO_D_RC);
	}
	else if(copy_Peripheral == GPIO_E){
		state = GET_BIT(PRGPIO, GPIO_E_RC);
	}
	else if(copy_Peripheral == GPIO_F){
		state = GET_BIT(PRGPIO, GPIO_F_RC);
	}
	else{
		/* wrong configurion input */
	}
	return state;
} 

/********************************************************************************************************************************
 * END OF FILE: SCC_Ctrl.c
 *******************************************************************************************************************************/ 