/********************************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------------------
 *			File: NVIC_Types.h
 *
 *          Module: -
 *
 *			
 *          Description: Includes New Types Definition    
 *
 ******************************************************************************************************************************/
#ifndef	NVIC_TYPES_H_
#define	NVIC_TYPES_H_

/*******************************************************************************************************************************
 * INCLUDES
 ******************************************************************************************************************************/
 #include "STD_TYPES.h"
 
/*******************************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 ******************************************************************************************************************************/
 #define CLEAR 			0
 #define SET				1
/*******************************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 ******************************************************************************************************************************/
 
/*******************************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************************************************************/
 typedef enum{
	 GPIO_PORT_A_INT =16,
	 GPIO_PORT_B_INT,
	 GPIO_PORT_C_INT,
	 GPIO_PORT_D_INT,
	 GPIO_PORT_E_INT,
	 GPIO_PORT_F_INT=46
 }INT_NO_t;
 
 typedef enum{
	 EIGHT_GROUP_ONE_SUBGROUP,
	 FOUR_GROUP_TWO_SUBGROUP,
	 TWO_GROUP_FOUR_SUBGROUP,
	 ONE_GROUP_EIGHT_SUBGROUP
 }Prio_Group_t;
/*******************************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 ******************************************************************************************************************************/
 
/*******************************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************************************************************/

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
static void NVIC_SetPriority(INT_NO_t copy_IntNo, Prio_Group_t copy_PriorityType,uint8_t copy_PriorityGroupVal, uint8_t copy_PrioritySubGroupVal);
 
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
static void NVIC_Enable(INT_NO_t copy_IntNo);

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
static void NVIC_Disable(INT_NO_t copy_IntNo);

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
static uint8_t NVIC_ReadPending(INT_NO_t copy_IntNo);

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
static void NVIC_SetPendingValue(INT_NO_t copy_IntNo, uint8_t copy_Value);

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
static uint8_t NVIC_ReadActive(INT_NO_t copy_IntNo);

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
static void NVIC_SetActiveValue(INT_NO_t copy_IntNo, uint8_t copy_Value);

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
static void NVIC_SetPriorityGrouping(Prio_Group_t copy_PriorityType);

 
 #endif  /* NVIC_TYPES_H_ */
 
/*******************************************************************************************************************************
 * END OF FILE: NVIC_Types.h
 ******************************************************************************************************************************/