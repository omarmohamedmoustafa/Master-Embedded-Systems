/*
 * STM32F103C6xx.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Omar_
 */

#ifndef INCLUDES_STM32F103C6XX_H_
#define INCLUDES_STM32F103C6XX_H_


/*====================================================================================================*/
//-----------------------------
//Includes
//-----------------------------

#include<stdint.h>
#include"BIT_MATH.h"

/*====================================================================================================*/


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_BASE 					0x08000000UL
#define SRAM_BASE 					0x20000000UL
#define SYSTEM_MEMORY_BASE			0x1FFF0000UL
#define PERIPHERALS_BASE			0x40000000UL
#define CORTEX_M_PERIPHERALS_BASE 	0xE000E000UL

/*====================================================================================================*/

//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//		AHB BUS PERIPHERALS BASE ADDRESSES
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define RCC_BASE (PERIPHERALS_BASE + (uint32_t)0x21000UL)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//		APB 1 BUS PERIPHERALS BASE ADDRESSES
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//		APB 2 BUS PERIPHERALS BASE ADDRESSES
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//=============================//
//			GPIO			   //
//=============================//
#define GPIOA_BASE 				(PERIPHERALS_BASE + (uint32_t)0x10800UL)
#define GPIOB_BASE			 	(PERIPHERALS_BASE + (uint32_t)0x10C00UL)
#define GPIOC_BASE 				(PERIPHERALS_BASE + (uint32_t)0x11000UL)
#define GPIOD_BASE				(PERIPHERALS_BASE + (uint32_t)0x11400UL)

//=============================//
//			EXTI			   //
//=============================//
#define EXTI_BASE				(PERIPHERALS_BASE +(uint32_t)0x10400UL)
//=============================//
//			AFIO			   //
//=============================//
#define AFIO_BASE				(PERIPHERALS_BASE +(uint32_t)0x10000UL)


//=============================//
//			NVIC			   //
//=============================//
#define NVIC_BASE				(CORTEX_M_PERIPHERALS_BASE +(uint32_t)0x100UL)

/*====================================================================================================*/


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t CRL		;
	volatile uint32_t CRH		;
	volatile uint32_t IDR		;
	volatile uint32_t ODR		;
	volatile uint32_t BSRR		;
	volatile uint32_t BRR		;
	volatile uint32_t LCKR		;
}s_GPIO_t;

typedef struct{
	volatile uint32_t CR		;
	volatile uint32_t CFGR		;
	volatile uint32_t CIR		;
	volatile uint32_t APB2RSTR	;
	volatile uint32_t APB1RSTR	;
	volatile uint32_t AHBENR	;
	volatile uint32_t APB2ENR	;
	volatile uint32_t APB1ENR	;
}s_RCC_t;

typedef struct{
	volatile uint32_t EVCR		;
	volatile uint32_t MAPR		;
	volatile uint32_t EXTICR[4]	;
			 uint32_t RESERVED	;
	volatile uint32_t MAPR2		;
}s_AFIO_t;

typedef struct{
	volatile uint32_t IMR		;
	volatile uint32_t EMR		;
	volatile uint32_t RTSR		;
	volatile uint32_t FTSR		;
	volatile uint32_t SWIER		;
	volatile uint32_t PR		;
}s_EXTI_t;

typedef struct{
	volatile uint32_t ISER0		;
	volatile uint32_t ISER1		;
	volatile uint32_t ISER2		;
	volatile uint32_t ICER0		;
	volatile uint32_t ICER1		;
	volatile uint32_t ICER2		;
}s_NVIC_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC			((s_RCC_t *)(RCC_BASE))
#define GPIOA		((s_GPIO_t*)(GPIOA_BASE))
#define GPIOB		((s_GPIO_t*)(GPIOB_BASE))
#define GPIOC		((s_GPIO_t*)(GPIOC_BASE))
#define GPIOD		((s_GPIO_t*)(GPIOD_BASE))
#define AFIO		((s_AFIO_t*)(AFIO_BASE))
#define EXTI		((s_EXTI_t*)(EXTI_BASE))
#define NVIC		((s_NVIC_t*)(NVIC_BASE))


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define MCAL_RCC_ENABLE_GPIOA()	SET_BIT(RCC->APB2ENR,GPIOA_APB2ENR_BIT)
#define MCAL_RCC_ENABLE_GPIOB()	SET_BIT(RCC->APB2ENR,GPIOB_APB2ENR_BIT)
#define MCAL_RCC_ENABLE_GPIOC()	SET_BIT(RCC->APB2ENR,GPIOC_APB2ENR_BIT)
#define MCAL_RCC_ENABLE_GPIOD()	SET_BIT(RCC->APB2ENR,GPIOD_APB2ENR_BIT)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Controller Macros:
//-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-
#define MCAL_NVIC_EXTI0_IRQ6_ENABLE() SET_BIT(NVIC->ISER0,6)
#define MCAL_NVIC_EXTI1_IRQ7_ENABLE() SET_BIT(NVIC->ISER0,7)
#define MCAL_NVIC_EXTI2_IRQ8_ENABLE() SET_BIT(NVIC->ISER0,8)
#define MCAL_NVIC_EXTI3_IRQ9_ENABLE() SET_BIT(NVIC->ISER0,9)
#define MCAL_NVIC_EXTI4_IRQ_10_ENABLE() SET_BIT(NVIC->ISER0,10)
#define MCAL_NVIC_EXTI5_9_IRQ23_ENABLE() SET_BIT(NVIC->ISER0,23)
#define MCAL_NVIC_EXTI10_15_IRQ40_ENABLE() SET_BIT(NVIC->ISER1,8)

#define MCAL_NVIC_EXTI0_IRQ6_DISABLE() SET_BIT(NVIC->ICER0,6)
#define MCAL_NVIC_EXTI1_IRQ7_DISABLE() SET_BIT(NVIC->ICER0,7)
#define MCAL_NVIC_EXTI2_IRQ8_DISABLE() SET_BIT(NVIC->ICER0,8)
#define MCAL_NVIC_EXTI3_IRQ9_DISABLE() SET_BIT(NVIC->ICER0,9)
#define MCAL_NVIC_EXTI4_IRQ_10_DISABLE() SET_BIT(NVIC->ICER0,10)
#define MCAL_NVIC_EXTI5_9_IRQ23_DISABLE() SET_BIT(NVIC->ICER0,23)
#define MCAL_NVIC_EXTI10_15_IRQ40_DISABLE() SET_BIT(NVIC->ICER1,8)


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_APB2ENR_BIT		1UL

#define GPIOA_APB2ENR_BIT		2UL
#define GPIOB_APB2ENR_BIT		3UL
#define GPIOC_APB2ENR_BIT		4UL
#define GPIOD_APB2ENR_BIT		5UL


#define GPIOA_APB2RSTR_BIT		2UL
#define GPIOB_APB2RSTR_BIT		3UL
#define GPIOC_APB2RSTR_BIT		4UL
#define GPIOD_APB2RSTR_BIT		5UL






#endif /* INCLUDES_STM32F103C6XX_H_ */
