/********************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------------------------------------------------------*/
/**			\file GPIO_Ctrl.c

 *          \brief General Purpose Input Output Register
 *
 *			\details Control pins of MCU to be high or low
 *                   
 *
 *******************************************************************************************************************************/
 
/*******************************************************************************************************************************
 * INCLUDES
 ******************************************************************************************************************************/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"

 #include "GPIO_Cfg.h"
 #include "GPIO_Types.h"
 #include "GPIO_Hw.h"
 #include "GPIO_Ctrl.h"

 
 
 
 
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
 * \Syntax			: void GPIO_Init(Port_config_t copy_PinConfig)
 * \Description     : Initialize GPIO Pins
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : copy_PinConfig
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
void GPIO_Init(const Port_config_t * copy_PinConfig){
	
	uint8_t PinNo;
	uint8_t Pin[PORT_PIN_NUM]={0};
	uint8_t Port[PORT_PIN_NUM]={0};
	
	/* Implement Code */
	/* Port Type */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(PORT_A == copy_PinConfig[PinNo].PortNum){
		
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_A; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_A; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_A; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_A; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_A; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_A; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_A; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_A; break;
			default: break; /* wrong Input */
		}
		
	}
	else if(PORT_B == copy_PinConfig[PinNo].PortNum){
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_B; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_B; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_B; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_B; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_B; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_B; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_B; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_B; break;
			default: break; /* wrong Input */
		}
	}
	else if(PORT_C == copy_PinConfig[PinNo].PortNum){
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_C; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_C; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_C; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_C; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_C; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_C; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_C; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_C; break;
			default: break;/* wrong Input */
		}
	}
	else if(PORT_D == copy_PinConfig[PinNo].PortNum){
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_D; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_D; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_D; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_D; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_D; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_D; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_D; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_D; break;
			default: break;/* wrong Input */
		}
	}
	else if(PORT_E == copy_PinConfig[PinNo].PortNum){
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_E; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_E; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_E; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_E; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_E; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_E; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_E; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_E; break;
			default: break;/* wrong Input */
		}
	}
	else if(PORT_F == copy_PinConfig[PinNo].PortNum){
		switch(copy_PinConfig[PinNo].Pin_Num){
			
			case  PIN_0: Pin[PinNo] = PIN_0; Port[PinNo] = PORT_F; break;
			case  PIN_1: Pin[PinNo] = PIN_1; Port[PinNo] = PORT_F; break;
			case  PIN_2: Pin[PinNo] = PIN_2; Port[PinNo] = PORT_F; break;
			case  PIN_3: Pin[PinNo] = PIN_3; Port[PinNo] = PORT_F; break;
			case  PIN_4: Pin[PinNo] = PIN_4; Port[PinNo] = PORT_F; break;
			case  PIN_5: Pin[PinNo] = PIN_5; Port[PinNo] = PORT_F; break;
			case  PIN_6: Pin[PinNo] = PIN_6; Port[PinNo] = PORT_F; break;
			case  PIN_7: Pin[PinNo] = PIN_7; Port[PinNo] = PORT_F; break;
			default: break;/* wrong Input */
		}
	}
	else{
	/* Wrong Input */
	}
	}
/******************************************************************/
	/* Enable DIO Function */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(DENABLE == copy_PinConfig[PinNo].PinMode){
		SET_BIT(GPIO_DEN(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_AMSEL(Port[PinNo]), Pin[PinNo]);
	}
	else if(DDISABLE == copy_PinConfig[PinNo].PinMode){
		CLR_BIT(GPIO_DEN(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_AMSEL(Port[PinNo]), Pin[PinNo]);
	}
	else{
	/* Wrong Input */
	}
	}
/****************************************************************/	
	/* Set Direction of Pin */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(OUTPUT == copy_PinConfig[PinNo].PortDir){
		SET_BIT(GPIO_DIR(Port[PinNo]), Pin[PinNo]);
	}
	else if(INPUT == copy_PinConfig[PinNo].PortDir){
		CLR_BIT(GPIO_DIR(Port[PinNo]), Pin[PinNo]);
	}
	else{
	/* Wrong Input */
	}
	}
/*****************************************************************/
	/* Pin Level */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(HIGH == copy_PinConfig[PinNo].PinLevel){
		SET_BIT(GPIO_DATA(Port[PinNo]), Pin[PinNo]);
	}
	else if(LOW == copy_PinConfig[PinNo].PinLevel){
		CLR_BIT(GPIO_DATA(Port[PinNo]), Pin[PinNo]);
	}
	else{
	/* Wrong Input */
	}
	}
/********************************************************************/
	/* Pin Current */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(DR2R == copy_PinConfig[PinNo].PinCurrent){
		SET_BIT(GPIO_DR2R(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_DR4R(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_DR8R(Port[PinNo]), Pin[PinNo]);
	}
	else if(DR4R == copy_PinConfig[PinNo].PinCurrent){
		CLR_BIT(GPIO_DR2R(Port[PinNo]), Pin[PinNo]);
		SET_BIT(GPIO_DR4R(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_DR8R(Port[PinNo]), Pin[PinNo]);
	}
	else if(DR8R == copy_PinConfig[PinNo].PinCurrent){
		CLR_BIT(GPIO_DR2R(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_DR4R(Port[PinNo]), Pin[PinNo]);
		SET_BIT(GPIO_DR8R(Port[PinNo]), Pin[PinNo]);
	}
	else{
	/* Wrong Input */
	}
	}
/*********************************************************************/
	/* Input Type */
	for(PinNo =0; PinNo<PORT_PIN_NUM; PinNo++){
	if(INPUT_PULL_UP == copy_PinConfig[PinNo].InputType){
		SET_BIT(GPIO_PUR(Port[PinNo]), Pin[PinNo]);
		CLR_BIT(GPIO_PDR(Port[PinNo]), Pin[PinNo]);
	}
	else if(INPUT_PULL_DOWN == copy_PinConfig[PinNo].InputType){
		CLR_BIT(GPIO_PUR(Port[PinNo]), Pin[PinNo]);
		SET_BIT(GPIO_PDR(Port[PinNo]), Pin[PinNo]);
	}
	else{
	/* Wrong Input */
	}
	}
/*********************************************************************/

} 

/*******************************************************************************************************************************
 * \Syntax			: void GPIO_SetPinValue(uint8_t copy_Port, uint8_t copy_Pin, uint8_t copy_State)
 * \Description     : Initialize GPIO Pins
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Port No, Pin No, State
 * \parameters (out): None
 * \Return Value    : None
 *******************************************************************************************************************************/
void GPIO_SetPinValue(uint8_t copy_Port, uint8_t copy_Pin, uint8_t copy_State){
	
	/* Pin Level */

	if(HIGH == copy_State){
		SET_BIT(GPIO_DATA(copy_Port), copy_Pin);
	}
	else if(LOW == copy_State){
		CLR_BIT(GPIO_DATA(copy_Port), copy_Pin);
	}
	else{
	/* Wrong Input */
	}

	
	
}

/*******************************************************************************************************************************
 * \Syntax			: uint8_t GPIO_GetPinValue(uint8_t copy_Port, uint8_t copy_Pin)
 * \Description     : Initialize GPIO Pins
 *  				  
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy		: Non Reentrant
 * \Parameters (in) : Port No, Pin No
 * \parameters (out): Pin Value
 * \Return Value    : uint8_t
 *******************************************************************************************************************************/
uint8_t GPIO_GetPinValue(uint8_t copy_Port, uint8_t copy_Pin){
	
	uint8_t PinValue = 0;
	
	PinValue = GET_BIT(GPIO_DATA(copy_Port), copy_Pin);
	
	return PinValue;
	
}

/********************************************************************************************************************************
 * END OF FILE: GPIO_Ctrl.c
 *******************************************************************************************************************************/ 
