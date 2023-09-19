/*
 * EXTI.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Omar_
 */

//===================<HEADER PROTECTION>===================
#ifndef INCLUDES_EXTI_H_
#define INCLUDES_EXTI_H_
//===================</HEADER PROTECTION>===================


//===================<INCLUDES>===================
#include"STM32F103C6xx.h"
#include"GPIO.h"
//===================</INCLUDES>===================

//===================<INPUT DATA>===================

typedef struct{
	uint8_t 				EXTI_LINE_NO		; // 0 - 15
	uint8_t 				EXTI_GPIO_PIN_NO	; // 0 - 15
	s_GPIO_t* 				GPIOx				; // GPIOA-GPIOB-GPIOC-GPIOD
	uint8_t					IRQ_NO				; // 6 		, 7		, 8		, 9		, 10	, 23		, 40
												  // EXTI0	EXTI1	EXTI2	EXTI3	EXTI4	EXTI5:9		EXTI10:15
}s_MCAL_EXTI_GPIO_MAPPING_t;

typedef struct
{
	s_MCAL_EXTI_GPIO_MAPPING_t 	EXTI_PIN				;
	uint8_t						IRQ_ENABLE				;
	uint8_t						TRIGGER_SELECT			;
	void (* p_EXTI_IRQ_CALLBACK)(void);
}s_MCAL_EXTI_PIN_CONFIG_t;

//===================</INPUT DATA>===================


//===================<CONFIG MACROS>===================
//@ref EXTI_PIN alternative configurations
#define EXTI_PORTA_PIN0		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE0,GPIO_PIN0,GPIOA,EXTI0_IRQ}
#define EXTI_PORTA_PIN1		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE1,GPIO_PIN1,GPIOA,EXTI1_IRQ}
#define EXTI_PORTA_PIN2		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE2,GPIO_PIN2,GPIOA,EXTI2_IRQ}
#define EXTI_PORTA_PIN3		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE3,GPIO_PIN3,GPIOA,EXTI3_IRQ}
#define EXTI_PORTA_PIN4		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE4,GPIO_PIN4,GPIOA,EXTI4_IRQ}
#define EXTI_PORTA_PIN5		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE5,GPIO_PIN5,GPIOA,EXTI5_9_IRQ}
#define EXTI_PORTA_PIN6		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE6,GPIO_PIN6,GPIOA,EXTI5_9_IRQ}
#define EXTI_PORTA_PIN7		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE7,GPIO_PIN7,GPIOA,EXTI5_9_IRQ}
#define EXTI_PORTA_PIN8		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE8,GPIO_PIN8,GPIOA,EXTI5_9_IRQ}
#define EXTI_PORTA_PIN9		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE9,GPIO_PIN9,GPIOA,EXTI5_9_IRQ}
#define EXTI_PORTA_PIN10	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE10,GPIO_PIN10,GPIOA,EXTI10_15_IRQ}
#define EXTI_PORTA_PIN11	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE11,GPIO_PIN11,GPIOA,EXTI10_15_IRQ}
#define EXTI_PORTA_PIN12	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE12,GPIO_PIN12,GPIOA,EXTI10_15_IRQ}
#define EXTI_PORTA_PIN13	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE13,GPIO_PIN13,GPIOA,EXTI10_15_IRQ}
#define EXTI_PORTA_PIN14	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE14,GPIO_PIN14,GPIOA,EXTI10_15_IRQ}
#define EXTI_PORTA_PIN15	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE15,GPIO_PIN15,GPIOA,EXTI10_15_IRQ}

#define EXTI_PORTB_PIN0		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE0,GPIO_PIN0,GPIOB,EXTI0_IRQ}
#define EXTI_PORTB_PIN1		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE1,GPIO_PIN1,GPIOB,EXTI1_IRQ}
#define EXTI_PORTB_PIN2		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE2,GPIO_PIN2,GPIOB,EXTI2_IRQ}
#define EXTI_PORTB_PIN3		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE3,GPIO_PIN3,GPIOB,EXTI3_IRQ}
#define EXTI_PORTB_PIN4		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE4,GPIO_PIN4,GPIOB,EXTI4_IRQ}
#define EXTI_PORTB_PIN5		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE5,GPIO_PIN5,GPIOB,EXTI5_9_IRQ}
#define EXTI_PORTB_PIN6		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE6,GPIO_PIN6,GPIOB,EXTI5_9_IRQ}
#define EXTI_PORTB_PIN7		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE7,GPIO_PIN7,GPIOB,EXTI5_9_IRQ}
#define EXTI_PORTB_PIN8		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE8,GPIO_PIN8,GPIOB,EXTI5_9_IRQ}
#define EXTI_PORTB_PIN9		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE9,GPIO_PIN9,GPIOB,EXTI5_9_IRQ}
#define EXTI_PORTB_PIN10	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE10,GPIO_PIN10,GPIOB,EXTI10_15_IRQ}
#define EXTI_PORTB_PIN11	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE11,GPIO_PIN11,GPIOB,EXTI10_15_IRQ}
#define EXTI_PORTB_PIN12	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE12,GPIO_PIN12,GPIOB,EXTI10_15_IRQ}
#define EXTI_PORTB_PIN13	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE13,GPIO_PIN13,GPIOB,EXTI10_15_IRQ}
#define EXTI_PORTB_PIN14	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE14,GPIO_PIN14,GPIOB,EXTI10_15_IRQ}
#define EXTI_PORTB_PIN15	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE15,GPIO_PIN15,GPIOB,EXTI10_15_IRQ}

#define EXTI_PORTC_PIN0		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE0,GPIO_PIN0,GPIOC,EXTI0_IRQ}
#define EXTI_PORTC_PIN1		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE1,GPIO_PIN1,GPIOC,EXTI1_IRQ}
#define EXTI_PORTC_PIN2		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE2,GPIO_PIN2,GPIOC,EXTI2_IRQ}
#define EXTI_PORTC_PIN3		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE3,GPIO_PIN3,GPIOC,EXTI3_IRQ}
#define EXTI_PORTC_PIN4		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE4,GPIO_PIN4,GPIOC,EXTI4_IRQ}
#define EXTI_PORTC_PIN5		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE5,GPIO_PIN5,GPIOC,EXTI5_9_IRQ}
#define EXTI_PORTC_PIN6		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE6,GPIO_PIN6,GPIOC,EXTI5_9_IRQ}
#define EXTI_PORTC_PIN7		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE7,GPIO_PIN7,GPIOC,EXTI5_9_IRQ}
#define EXTI_PORTC_PIN8		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE8,GPIO_PIN8,GPIOC,EXTI5_9_IRQ}
#define EXTI_PORTC_PIN9		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE9,GPIO_PIN9,GPIOC,EXTI5_9_IRQ}
#define EXTI_PORTC_PIN10	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE10,GPIO_PIN10,GPIOC,EXTI10_15_IRQ}
#define EXTI_PORTC_PIN11	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE11,GPIO_PIN11,GPIOC,EXTI10_15_IRQ}
#define EXTI_PORTC_PIN12	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE12,GPIO_PIN12,GPIOC,EXTI10_15_IRQ}
#define EXTI_PORTC_PIN13	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE13,GPIO_PIN13,GPIOC,EXTI10_15_IRQ}
#define EXTI_PORTC_PIN14	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE14,GPIO_PIN14,GPIOC,EXTI10_15_IRQ}
#define EXTI_PORTC_PIN15	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE15,GPIO_PIN15,GPIOC,EXTI10_15_IRQ}

#define EXTI_PORTD_PIN0		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE0,GPIO_PIN0,GPIOD,EXTI0_IRQ}
#define EXTI_PORTD_PIN1		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE1,GPIO_PIN1,GPIOD,EXTI1_IRQ}
#define EXTI_PORTD_PIN2		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE2,GPIO_PIN2,GPIOD,EXTI2_IRQ}
#define EXTI_PORTD_PIN3		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE3,GPIO_PIN3,GPIOD,EXTI3_IRQ}
#define EXTI_PORTD_PIN4		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE4,GPIO_PIN4,GPIOD,EXTI4_IRQ}
#define EXTI_PORTD_PIN5		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE5,GPIO_PIN5,GPIOD,EXTI5_9_IRQ}
#define EXTI_PORTD_PIN6		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE6,GPIO_PIN6,GPIOD,EXTI5_9_IRQ}
#define EXTI_PORTD_PIN7		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE7,GPIO_PIN7,GPIOD,EXTI5_9_IRQ}
#define EXTI_PORTD_PIN8		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE8,GPIO_PIN8,GPIOD,EXTI5_9_IRQ}
#define EXTI_PORTD_PIN9		(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE9,GPIO_PIN9,GPIOD,EXTI5_9_IRQ}
#define EXTI_PORTD_PIN10	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE10,GPIO_PIN10,GPIOD,EXTI10_15_IRQ}
#define EXTI_PORTD_PIN11	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE11,GPIO_PIN11,GPIOD,EXTI10_15_IRQ}
#define EXTI_PORTD_PIN12	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE12,GPIO_PIN12,GPIOD,EXTI10_15_IRQ}
#define EXTI_PORTD_PIN13	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE13,GPIO_PIN13,GPIOD,EXTI10_15_IRQ}
#define EXTI_PORTD_PIN14	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE14,GPIO_PIN14,GPIOD,EXTI10_15_IRQ}
#define EXTI_PORTD_PIN15	(s_MCAL_EXTI_GPIO_MAPPING_t){EXTI_LINE15,GPIO_PIN15,GPIOD,EXTI10_15_IRQ}
//===================</CONFIG MACROS>===================


//===================<GENERIC MACROS>===================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_LINE0					0
#define EXTI_LINE1					1
#define EXTI_LINE2					2
#define EXTI_LINE3					3
#define EXTI_LINE4					4
#define EXTI_LINE5					5
#define EXTI_LINE6					6
#define EXTI_LINE7					7
#define EXTI_LINE8					8
#define EXTI_LINE9					9
#define EXTI_LINE10					10
#define EXTI_LINE11					11
#define EXTI_LINE12					12
#define EXTI_LINE13					13
#define EXTI_LINE14					14
#define EXTI_LINE15					15
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define EXTI0_IRQ					6
#define EXTI1_IRQ					7
#define EXTI2_IRQ					8
#define EXTI3_IRQ					9
#define EXTI4_IRQ					10
#define EXTI5_9_IRQ					23
#define EXTI10_15_IRQ				40
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_IRQ_ENABLED				1
#define EXTI_IRQ_DISABLED				0
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_RISING_TRIGGER			0
#define EXTI_FALLING_TRIGGER		1
#define EXTI_BOTH_EDGES_TRIGGER		2
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


#define AFIO_PORT_SEL(x)		((x==GPIOA)? 0:\
								(x==GPIOB)? 1:\
								(x==GPIOC)? 2:\
								(x==GPIOD)? 3:0)
//===================</GENERIC MACROS>===================


//===================<PERIPHERAL APIs>===================

void MCAL_vid_EXTI_GPIO_INIT(s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG);
void MCAL_vid_EXTI_GPIO_DEINIT();
void MCAL_vid_EXTI_GPIO_UPDATE(s_MCAL_EXTI_PIN_CONFIG_t* EXTI_CFG);

//===================</PERIPHERAL APIs>===================
#endif /* INCLUDES_EXTI_H_ */
