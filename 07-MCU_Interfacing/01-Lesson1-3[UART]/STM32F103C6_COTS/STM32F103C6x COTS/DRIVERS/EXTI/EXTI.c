/*
 * EXTI.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Omar_
 */

#include "EXTI.h"

void (* gp_EXTI_IRQ_CALLBACK[15] )(void) ; // Array of 15 interrupts to functions take void, return void

//===================<PERIPHERAL APIs Implementation>===================

//FNAME			:	MCAL_vid_EXTI_GPIO_INIT
//BRIEF			:
//IN_PARAM		:	N/A
//OUT_PARAM		:	N/A
//IN_OUT_PARAM	:	s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG
//NOTE			:
void NVIC_ENABLE(uint8_t EXTI_LINE_NO)
{
	switch(EXTI_LINE_NO)
	{
	case 0:
		MCAL_NVIC_EXTI0_IRQ6_ENABLE();
		break;
	case 1:
		MCAL_NVIC_EXTI1_IRQ7_ENABLE();
		break;
	case 2:
		MCAL_NVIC_EXTI2_IRQ8_ENABLE();
		break;
	case 3:
		MCAL_NVIC_EXTI3_IRQ9_ENABLE();
		break;
	case 4:
		MCAL_NVIC_EXTI4_IRQ_10_ENABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		MCAL_NVIC_EXTI5_9_IRQ23_ENABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		MCAL_NVIC_EXTI10_15_IRQ40_ENABLE();
		break;
	}
}


void NVIC_DISABLE(uint8_t EXTI_LINE_NO)
{
	switch(EXTI_LINE_NO)
	{
	case 0:
		MCAL_NVIC_EXTI0_IRQ6_DISABLE();
		break;
	case 1:
		MCAL_NVIC_EXTI1_IRQ7_DISABLE();
		break;
	case 2:
		MCAL_NVIC_EXTI2_IRQ8_DISABLE();
		break;
	case 3:
		MCAL_NVIC_EXTI3_IRQ9_DISABLE();
		break;
	case 4:
		MCAL_NVIC_EXTI4_IRQ_10_DISABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		MCAL_NVIC_EXTI5_9_IRQ23_DISABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		MCAL_NVIC_EXTI10_15_IRQ40_DISABLE();
		break;
	}
}
void Update_EXTI(s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG)
{
	// Configure GPIO to be floating input
	s_GPIO_PIN_CONFIG_t Pin_Config;

	Pin_Config.PIN_NUM  = EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO;
	Pin_Config.PIN_MODE = MCAL_GPIO_FLO_IN;
	Pin_Config.PIN_OUTPUT_SPEED = MCAL_GPIO_INPUT;
	MCAL_vid_GPIO_INIT(EXTI_CFG->EXTI_PIN.GPIOx, &Pin_Config);

	// Configure AFIO registers , which Pin to be mapped as EXTI
	uint8_t AFIO_EXTICR_Idx 		= EXTI_CFG->EXTI_PIN.EXTI_LINE_NO / 4;
	uint8_t AFIO_EXTICR_Position	= (EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO % 4) *4;
	// Clear AFIO_EXTICR[x] Corresponding bits
	AFIO->EXTICR[AFIO_EXTICR_Idx] &= ~(0xF<<AFIO_EXTICR_Position);

	//SET AFIO_EXTICR[x] register with corresponding Port Pin
	AFIO->EXTICR[AFIO_EXTICR_Idx] |= ((AFIO_PORT_SEL(EXTI_CFG->EXTI_PIN.GPIOx)) & 0xF) << AFIO_EXTICR_Position;

	// Clear previous trigger selection for bits
	CLR_BIT(EXTI->RTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
	CLR_BIT(EXTI->FTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
	// Configure EXTI Trigger select
	switch(EXTI_CFG->TRIGGER_SELECT)
	{
	case EXTI_RISING_TRIGGER:
		SET_BIT(EXTI->RTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		break;
	case EXTI_FALLING_TRIGGER:
		SET_BIT(EXTI->FTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		break;
	case EXTI_BOTH_EDGES_TRIGGER:
		SET_BIT(EXTI->RTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		SET_BIT(EXTI->FTSR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		break;
	}

	// Set IRQ callback
	gp_EXTI_IRQ_CALLBACK[EXTI_CFG->EXTI_PIN.EXTI_LINE_NO] = EXTI_CFG->p_EXTI_IRQ_CALLBACK;

	// Enable IRQ / Disable IRQ , NVIC IRQ Enable, Disable
	if(EXTI_CFG->IRQ_ENABLE == EXTI_IRQ_ENABLED)
	{
		SET_BIT(EXTI->IMR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		NVIC_ENABLE(EXTI_CFG->EXTI_PIN.EXTI_LINE_NO);
	}
	else
	{
		CLR_BIT(EXTI->IMR,EXTI_CFG->EXTI_PIN.EXTI_GPIO_PIN_NO);
		NVIC_DISABLE(EXTI_CFG->EXTI_PIN.EXTI_LINE_NO);
	}
}

void MCAL_vid_EXTI_GPIO_INIT(s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG)
{
	Update_EXTI(EXTI_CFG);
}
void MCAL_vid_EXTI_GPIO_DEINIT()
{
	//Reset value for exti registers
	EXTI->IMR  	= (uint32_t)0;
	EXTI->EMR  	= (uint32_t)0;
	EXTI->RTSR 	= (uint32_t)0;
	EXTI->FTSR 	= (uint32_t)0;
	EXTI->SWIER = (uint32_t)0;
	EXTI->PR	= 0xFFFFFFFF ;

	//Reset NVIC IRQ Enable
	MCAL_NVIC_EXTI0_IRQ6_DISABLE();
	MCAL_NVIC_EXTI1_IRQ7_DISABLE();
	MCAL_NVIC_EXTI2_IRQ8_DISABLE();
	MCAL_NVIC_EXTI3_IRQ9_DISABLE();
	MCAL_NVIC_EXTI4_IRQ_10_DISABLE();
	MCAL_NVIC_EXTI5_9_IRQ23_DISABLE();
	MCAL_NVIC_EXTI10_15_IRQ40_DISABLE();
}
void MCAL_vid_EXTI_GPIO_UPDATE(s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG)
{
	Update_EXTI(EXTI_CFG);

}

void EXTI0_IRQHandler(void)
{
	// c_w1 for pending register
	SET_BIT(EXTI->PR,0);
	// jump to call back function
	gp_EXTI_IRQ_CALLBACK[0]();
}
void EXTI1_IRQHandler(void)
{
	// c_w1 for pending register
	SET_BIT(EXTI->PR,1);
	// jump to call back function
	gp_EXTI_IRQ_CALLBACK[1]();
}
void EXTI2_IRQHandler(void)
{
	// c_w1 for pending register
	SET_BIT(EXTI->PR,2);
	// jump to call back function
	gp_EXTI_IRQ_CALLBACK[2]();
}
void EXTI3_IRQHandler(void)
{
	// c_w1 for pending register
	SET_BIT(EXTI->PR,3);
	// jump to call back function
	gp_EXTI_IRQ_CALLBACK[3]();
}
void EXTI4_IRQHandler(void)
{
	// c_w1 for pending register
	SET_BIT(EXTI->PR,4);
	// jump to call back function
	gp_EXTI_IRQ_CALLBACK[4]();
}
void EXTI5_9_IRQHandler(void)
{

	if(GET_BIT(EXTI->PR,5))
	{
		SET_BIT(EXTI->PR,5);
		gp_EXTI_IRQ_CALLBACK[5]();
	}
	else if(GET_BIT(EXTI->PR,6))
	{
		SET_BIT(EXTI->PR,6);
		gp_EXTI_IRQ_CALLBACK[6]();
	}
	else if(GET_BIT(EXTI->PR,7))
	{
		SET_BIT(EXTI->PR,7);
		gp_EXTI_IRQ_CALLBACK[7]();
	}
	else if(GET_BIT(EXTI->PR,8))
	{
		SET_BIT(EXTI->PR,8);
		gp_EXTI_IRQ_CALLBACK[8]();
	}
	else if(GET_BIT(EXTI->PR,9))
	{
		SET_BIT(EXTI->PR,9);
		gp_EXTI_IRQ_CALLBACK[9]();
	}

}
void EXTI10_15_IRQHandler(void)
{
	if(GET_BIT(EXTI->PR,10))
	{
		SET_BIT(EXTI->PR,10);
		gp_EXTI_IRQ_CALLBACK[10]();
	}
	else if(GET_BIT(EXTI->PR,11))
	{
		SET_BIT(EXTI->PR,11);
		gp_EXTI_IRQ_CALLBACK[11]();
	}
	else if(GET_BIT(EXTI->PR,12))
	{
		SET_BIT(EXTI->PR,12);
		gp_EXTI_IRQ_CALLBACK[12]();
	}
	else if(GET_BIT(EXTI->PR,13))
	{
		SET_BIT(EXTI->PR,13);
		gp_EXTI_IRQ_CALLBACK[13]();
	}
	else if(GET_BIT(EXTI->PR,14))
	{
		SET_BIT(EXTI->PR,14);
		gp_EXTI_IRQ_CALLBACK[14]();
	}
	else if(GET_BIT(EXTI->PR,15))
	{
		SET_BIT(EXTI->PR,15);
		gp_EXTI_IRQ_CALLBACK[15]();
	}
}

//===================</PERIPHERAL APIs Implementation>===================
