/********************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------------------------------------------------------*/
/**			\file NVIC_Ctrl.c

 *          \brief Nested Vector Interrupt Controller Driver
 *
 *			\details Driver configure All MCU interrupts Priority into groups and subgroups
 *                   Enable NVIC Interrupt Gate for Peripherals
 *
 *******************************************************************************************************************************/
 
/*******************************************************************************************************************************
 * INCLUDES
 ******************************************************************************************************************************/
 #include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_Ctrl.h"
#include "NVIC_Cfg.h"
#include "NVIC_Types.h"
#include "NVIC_Hw.h"
 
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
 * \Syntax			: void NVIC_Init(void)
 * \Description     : Initialize NVIC\SCB Module by parsing the configuration
 *  				  into NVIC\SCB Registers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : None
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
void NVIC_Init(void){
	
	/* Config SCB for Priority */
	NVIC_SetPriorityGrouping(EIGHT_GROUP_ONE_SUBGROUP);
	
	/* Assign Priority to GPIO Port A*/
	NVIC_SetPriority(GPIO_PORT_A_INT, EIGHT_GROUP_ONE_SUBGROUP, GROUP_1, SUB_GROUP_1);
	
	/* Enable GPIO PORT A */
	NVIC_Enable(GPIO_PORT_A_INT);
}  

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_SetPriority(INT_NO_t copy_IntNo, Prio_Group_t copy_PriorityType,uint8_t copy_PriorityGroupVal, uint8_t copy_PrioritySubGroupVal)
 * \Description     : Set priority value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No, Priority type,Priority Group value, sub group value
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_SetPriority(INT_NO_t copy_IntNo, Prio_Group_t copy_PriorityType,uint8_t copy_PriorityGroupVal, uint8_t copy_PrioritySubGroupVal){
	
	/* Implement Code */
	
	
}

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_Enable(INT_NO_t copy_IntNo)
 * \Description     : Enable Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_Enable(INT_NO_t copy_IntNo){
	
	/* Implement Code */
	if(copy_IntNo < 32){
	SET_BIT(NVIC_EN_REGISTER->EN_0, copy_IntNo);
	}
	else if(copy_IntNo < 64){
	copy_IntNo-= 32;
	SET_BIT(NVIC_EN_REGISTER->EN_1, copy_IntNo);	
	}
	else if(copy_IntNo < 96){
	copy_IntNo-= 64;
	SET_BIT(NVIC_EN_REGISTER->EN_2, copy_IntNo);	
	}
	else{
	copy_IntNo-= 96;
	SET_BIT(NVIC_EN_REGISTER->EN_3, copy_IntNo);	
	}
}

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_Disable(INT_NO_t copy_IntNo)
 * \Description     : Disable Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_Disable(INT_NO_t copy_IntNo){
	
	/* Implement Code */
	if(copy_IntNo < 32){
	SET_BIT(NVIC_DIS_REGISTER->DIS_0, copy_IntNo);
	}
	else if(copy_IntNo < 64){
	copy_IntNo-= 32;
	SET_BIT(NVIC_DIS_REGISTER->DIS_1, copy_IntNo);	
	}
	else if(copy_IntNo < 96){
	copy_IntNo-= 64;
	SET_BIT(NVIC_DIS_REGISTER->DIS_2, copy_IntNo);	
	}
	else{
	copy_IntNo-= 96;
	SET_BIT(NVIC_DIS_REGISTER->DIS_3, copy_IntNo);	
	}
	
}

/*******************************************************************************************************************************
 * \Syntax			: static uint8_t NVIC_ReadPending(INT_NO_t copy_IntNo)
 * \Description     : Read pending value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No
 * \parameters (out): pending or not pending
 * \Return Value    : uint8_t
 *******************************************************************************************************************************/
static uint8_t NVIC_ReadPending(INT_NO_t copy_IntNo){
	uint8_t State;
	/* Implement Code */
	if(copy_IntNo < 32){
	State = GET_BIT(NVIC_PEND_REGISTER->PEND_0, copy_IntNo);
	}
	else if(copy_IntNo < 64){
	copy_IntNo-= 32;
	State = GET_BIT(NVIC_PEND_REGISTER->PEND_1, copy_IntNo);	
	}
	else if(copy_IntNo < 96){
	copy_IntNo-= 64;
	State = GET_BIT(NVIC_PEND_REGISTER->PEND_2, copy_IntNo);	
	}
	else{
	copy_IntNo-= 96;
	State = GET_BIT(NVIC_PEND_REGISTER->PEND_3, copy_IntNo);	
	}
	return State;
}

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_SetPendingValue(INT_NO_t copy_IntNo, uint8_t copy_Value)
 * \Description     : Set or clear pending value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No, Value (CLEAR, SET)
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_SetPendingValue(INT_NO_t copy_IntNo, uint8_t copy_Value){
	
		/* Implement Code */
	if(copy_Value == CLEAR){
		if(copy_IntNo < 32){
		CLR_BIT(NVIC_PEND_REGISTER->PEND_0, copy_IntNo);
		}
		else if(copy_IntNo < 64){
		copy_IntNo-= 32;
		CLR_BIT(NVIC_PEND_REGISTER->PEND_1, copy_IntNo);	
		}
		else if(copy_IntNo < 96){
		copy_IntNo-= 64;
		CLR_BIT(NVIC_PEND_REGISTER->PEND_2, copy_IntNo);	
		}
		else{
		copy_IntNo-= 96;
		CLR_BIT(NVIC_PEND_REGISTER->PEND_3, copy_IntNo);	
		}
	}
	else{
		if(copy_IntNo < 32){
		SET_BIT(NVIC_PEND_REGISTER->PEND_0, copy_IntNo);
		}
		else if(copy_IntNo < 64){
		copy_IntNo-= 32;
		SET_BIT(NVIC_PEND_REGISTER->PEND_1, copy_IntNo);	
		}
		else if(copy_IntNo < 96){
		copy_IntNo-= 64;
		SET_BIT(NVIC_PEND_REGISTER->PEND_2, copy_IntNo);	
		}
		else{
		copy_IntNo-= 96;
		SET_BIT(NVIC_PEND_REGISTER->PEND_3, copy_IntNo);	
		}
		
	}
}

/*******************************************************************************************************************************
 * \Syntax			: static uint8_t NVIC_ReadActive(INT_NO_t copy_IntNo)
 * \Description     : Read Active value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No
 * \parameters (out): pending or not pending
 * \Return Value    : uint8_t
 *******************************************************************************************************************************/
static uint8_t NVIC_ReadActive(INT_NO_t copy_IntNo){
	uint8_t State;
	/* Implement Code */
	if(copy_IntNo < 32){
	State = GET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_0, copy_IntNo);
	}
	else if(copy_IntNo < 64){
	copy_IntNo-= 32;
	State = GET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_1, copy_IntNo);	
	}
	else if(copy_IntNo < 96){
	copy_IntNo-= 64;
	State = GET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_2, copy_IntNo);	
	}
	else{
	copy_IntNo-= 96;
	State = GET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_3, copy_IntNo);	
	}
	return State;
}

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_SetActiveValue(INT_NO_t copy_IntNo, uint8_t copy_Value)
 * \Description     : Set or clear Active value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Interrupt_No, Value (CLEAR, SET)
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_SetActiveValue(INT_NO_t copy_IntNo, uint8_t copy_Value){
	
		/* Implement Code */
	if(copy_Value == CLEAR){
		if(copy_IntNo < 32){
		CLR_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_0, copy_IntNo);
		}
		else if(copy_IntNo < 64){
		copy_IntNo-= 32;
		CLR_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_1, copy_IntNo);	
		}
		else if(copy_IntNo < 96){
		copy_IntNo-= 64;
		CLR_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_2, copy_IntNo);	
		}
		else{
		copy_IntNo-= 96;
		CLR_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_3, copy_IntNo);	
		}
	}
	else{
		if(copy_IntNo < 32){
		SET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_0, copy_IntNo);
		}
		else if(copy_IntNo < 64){
		copy_IntNo-= 32;
		SET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_1, copy_IntNo);	
		}
		else if(copy_IntNo < 96){
		copy_IntNo-= 64;
		SET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_2, copy_IntNo);	
		}
		else{
		copy_IntNo-= 96;
		SET_BIT(NVIC_ACTIVE_REGISTER->ACTIVE_3, copy_IntNo);	
		}
		
	}
}

/*******************************************************************************************************************************
 * \Syntax			: static void NVIC_SetPriorityGrouping(Prio_Group_t copy_PriorityType)
 * \Description     : Set or clear Active value for Interrupt of certain peripheral
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : PriorityType
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
static void NVIC_SetPriorityGrouping(Prio_Group_t copy_PriorityType){
	
	/* Implement Code */
	if(copy_PriorityType == EIGHT_GROUP_ONE_SUBGROUP){
		SCB_APINT_REGISTER = 0x05FA|0x00000400;
	}
	else if(copy_PriorityType == FOUR_GROUP_TWO_SUBGROUP){
		SCB_APINT_REGISTER = 0x05FA|0x00000500;
	}
	else if(copy_PriorityType == TWO_GROUP_FOUR_SUBGROUP){
		SCB_APINT_REGISTER = 0x05FA|0x00000600;
	}
	else if(copy_PriorityType == ONE_GROUP_EIGHT_SUBGROUP){
		SCB_APINT_REGISTER = 0x05FA|0x00000700;
	}
	else{
		/* Warning */
	}
}

/********************************************************************************************************************************
 * END OF FILE: NVIC_Ctrl.c
 *******************************************************************************************************************************/ 