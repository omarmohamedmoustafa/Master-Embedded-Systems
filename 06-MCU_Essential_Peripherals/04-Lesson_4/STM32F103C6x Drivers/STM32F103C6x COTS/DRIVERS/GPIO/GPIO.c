/******************************************************************************************************************/
/******* DRIVER: GPIO**********************************************************************************************/
/******* MCU: STM32F103C6x*****************************************************************************************/
/******* AUTHOR: OMAR MOHAMMAD MOSTAFA*****************************************************************************/
/******* UNDER SUPERVISION OF ENG. KEROLES SHENOUDA****************************************************************/
/******* LEARN-IN-DEPTH********************************************************************************************/
/******* VERSION: 01***********************************************************************************************/
#include "GPIO.h"


uint8_t MCAL_uint8_GET_PIN_LOCATION(uint8_t PIN_NO)
{
	switch(PIN_NO)
	{
	case 0:
		return 0;break;
	case 1:
		return 4;break;
	case 2:
		return 8;break;
	case 3:
		return 12;break;
	case 4:
		return 16;break;
	case 5:
		return 20;break;
	case 6:
		return 24;break;
	case 7:
		return 28;break;
	case 8:
		return 0;break;
	case 9:
		return 4;break;
	case 10:
		return 8;break;
	case 11:
		return 12;break;
	case 12:
		return 16;break;
	case 13:
		return 20;break;
	case 14:
		return 24;break;
	case 15:
		return 28;break;
	default:
		return 255;
	}
}
void MCAL_vid_GPIO_INIT(s_GPIO_t* GPIOx , s_GPIO_PIN_CONFIG_t* PIN_CONFIG)
{
	if(		(GPIOx == GPIOA) 	||	 (GPIOx== GPIOB) 	||	 (GPIOx== GPIOC) 	||	 (GPIOx== GPIOD))
	{
		volatile uint32_t* CONFIG_REGISTER = (PIN_CONFIG->PIN_NUM < 8 )?  &GPIOx->CRL : &GPIOx->CRH   ;
		*CONFIG_REGISTER &= ~(0xF << MCAL_uint8_GET_PIN_LOCATION(PIN_CONFIG->PIN_NUM));

		//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		//	OUTPUT PIN (CNF + SPEED)
		//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		if((PIN_CONFIG->PIN_MODE == MCAL_GPIO_GPO_OD) || (PIN_CONFIG->PIN_MODE == MCAL_GPIO_GPO_PP) || (PIN_CONFIG->PIN_MODE == MCAL_GPIO_AFO_PP) || (PIN_CONFIG->PIN_MODE == MCAL_GPIO_AFO_OD))
		{
			uint8_t CONF_MODE = ((	(	(PIN_CONFIG->PIN_MODE - 4)	<<	2	) | (PIN_CONFIG->PIN_OUTPUT_SPEED)	) & 0xF	);
			(*CONFIG_REGISTER) |= (uint32_t)(CONF_MODE << MCAL_uint8_GET_PIN_LOCATION(PIN_CONFIG->PIN_NUM));
		}
		else
			//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			//	INPUT PIN (CNF ONLY + 00 in mode )
			//		  MCAL_GPIO_ANALOG			0
			//		  MCAL_GPIO_FLO_IN			1
			//		  MCAL_GPIO_PU_IN			2
			//		  MCAL_GPIO_PD_IN			3
			//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		{
			if(PIN_CONFIG->PIN_MODE == MCAL_GPIO_ANALOG || PIN_CONFIG->PIN_MODE == MCAL_GPIO_FLO_IN)
			{
				uint8_t CONF_MODE = ((PIN_CONFIG->PIN_MODE)	<<	2);
				(*CONFIG_REGISTER) |= (uint32_t)(CONF_MODE << MCAL_uint8_GET_PIN_LOCATION(PIN_CONFIG->PIN_NUM));
			}
			else if (PIN_CONFIG->PIN_MODE == MCAL_GPIO_PU_IN)// INPUT PULL up
			{
				uint8_t CONF_MODE = ((PIN_CONFIG->PIN_MODE)	<<	2);
				SET_BIT(GPIOx->ODR, PIN_CONFIG->PIN_NUM);
				(*CONFIG_REGISTER) |= (uint32_t)(CONF_MODE << MCAL_uint8_GET_PIN_LOCATION(PIN_CONFIG->PIN_NUM));
			}
			else // INPUT PULL DOWN
			{
				uint8_t CONF_MODE = ((MCAL_GPIO_PU_IN)	<<	2);
				CLR_BIT(GPIOx->ODR, PIN_CONFIG->PIN_NUM);
				(*CONFIG_REGISTER) |= (uint32_t)(CONF_MODE << MCAL_uint8_GET_PIN_LOCATION(PIN_CONFIG->PIN_NUM));
			}
		}
	}
}

void MCAL_vid_GPIO_RESET(s_GPIO_t* GPIOx)
{
	/*
	 * RCC Peripheral in this Ucontroller has some registers to reset
	 *
	 *
	 */
	if(GPIOx == GPIOA)
		SET_BIT(RCC->APB2RSTR,GPIOA_APB2RSTR_BIT);
	else if(GPIOx == GPIOB)
		SET_BIT(RCC->APB2RSTR,GPIOB_APB2RSTR_BIT);
	else if(GPIOx == GPIOC)
		SET_BIT(RCC->APB2RSTR,GPIOC_APB2RSTR_BIT);
	else if(GPIOx == GPIOD)
		SET_BIT(RCC->APB2RSTR,GPIOD_APB2RSTR_BIT);
}

void MCAL_vid_WRITE_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO, uint8_t PIN_VAL)
{
	if(		(GPIOx == GPIOA) 	||	 (GPIOx== GPIOB) 	||	 (GPIOx== GPIOC) 	||	 (GPIOx== GPIOD))
	{
		if(PIN_VAL)
		{
			SET_BIT(GPIOx->ODR,PIN_NO);
		}
		else
		{
			CLR_BIT(GPIOx->ODR, PIN_NO);
		}
	}
}

void MCAL_vid_WRITE_PORT(s_GPIO_t* GPIOx, uint16_t PORT_VAL)
{
	if(		(GPIOx == GPIOA) 	||	 (GPIOx== GPIOB) 	||	 (GPIOx== GPIOC) 	||	 (GPIOx== GPIOD))
	{
		GPIOx->ODR &= ~(0xFFFF);
		GPIOx->ODR &= (uint32_t)PORT_VAL;
	}
}

uint8_t MCAL_uint8_GPIO_READ_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO)
{
	uint8_t PIN_VAL;
	if(		(GPIOx == GPIOA) 	||	 (GPIOx== GPIOB) 	||	 (GPIOx== GPIOC) 	||	 (GPIOx== GPIOD))
	{
		PIN_VAL = GET_BIT(GPIOx->IDR, PIN_NO);
		return PIN_VAL;
	}
	return (uint8_t)0;
}

void MCAL_vid_TOGGLE_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO)
{
	if(		(GPIOx == GPIOA) 	||	 (GPIOx== GPIOB) 	||	 (GPIOx== GPIOC) 	||	 (GPIOx== GPIOD))
	{
		TOG_BIT(GPIOx->ODR,PIN_NO);
	}
}
