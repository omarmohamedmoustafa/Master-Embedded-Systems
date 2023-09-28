/*
 * RCC.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Omar_
 */
//typedef struct{
//	volatile uint32_t CR		;
//	volatile uint32_t CFGR		;
//	volatile uint32_t CIR		;
//	volatile uint32_t APB2RSTR	;
//	volatile uint32_t APB1RSTR	;
//	volatile uint32_t AHBENR	;
//	volatile uint32_t APB2ENR	;
//	volatile uint32_t APB1ENR	;
//	volatile uint32_t BDCR		;
//	volatile uint32_t CSR	;
//}s_RCC_t;
#include"STM32F103C6xx.h"
#include"RCC.h"
uint8_t APB_PRESCALER [] = {0,0,0,0,1,2,3,4};
uint8_t AHB_PRESCALER [] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};


void RCC_vidEnablePeripheralClock(uint8_t cpy_u8BusId, uint8_t cpy_u8PerId)
{
	if(cpy_u8PerId <= 31)
	{
		switch(cpy_u8BusId)
		{
		case AHB:
			SET_BIT(RCC->AHBENR,cpy_u8PerId);
			break;
		case APB1:
			SET_BIT(RCC->APB1ENR,cpy_u8PerId);
			break;
		case APB2:
			SET_BIT(RCC->APB2ENR,cpy_u8PerId);
			break;
		default:
			break;
		}
	}
}
void RCC_vidDisablePeripheralClock(uint8_t cpy_u8BusId, uint8_t cpy_u8PerId)
{
	if(cpy_u8PerId <= 31)
		{
			switch(cpy_u8BusId)
			{
			case AHB:
				CLR_BIT(RCC->AHBENR,cpy_u8PerId);
				break;
			case APB1:
				CLR_BIT(RCC->APB1ENR,cpy_u8PerId);
				break;
			case APB2:
				CLR_BIT(RCC->APB2ENR,cpy_u8PerId);
				break;
			default:
				break;
			}
		}
}
uint32_t MCAL_RCC_GET_PCLK1(void)
{
	return ((MCAL_RCC_GET_HCLK()) >> (APB_PRESCALER[( RCC->CFGR >> 8) & 0b111]));
}
uint32_t MCAL_RCC_GET_PCLK2(void)
{
	return ((MCAL_RCC_GET_HCLK()) >> (APB_PRESCALER[( RCC->CFGR >> 11) & 0b111]));
}
uint32_t MCAL_RCC_GET_HCLK(void)
{
	return ((MCAL_RCC_GET_SYS_CLK()) >> (AHB_PRESCALER[((RCC->CFGR >> 4) & 0b1111)]));
}
uint32_t MCAL_RCC_GET_SYS_CLK(void)
{
	switch((RCC->CFGR >> 2) & (0b11))
	{
	case 0:
		return HSI_RC_CLK;
		break;
	case 1:
		return HSE_CLK;
		break;
	case 2:
		return (uint32_t)16000000;
		break;
	}
	return 0;
}
