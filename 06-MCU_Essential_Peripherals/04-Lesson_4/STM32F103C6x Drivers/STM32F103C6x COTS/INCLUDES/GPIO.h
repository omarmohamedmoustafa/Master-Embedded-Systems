/******************************************************************************************************************/
/******* DRIVER: GPIO**********************************************************************************************/
/******* MCU: STM32F103C6x*****************************************************************************************/
/******* AUTHOR: OMAR MOHAMMAD MOSTAFA*****************************************************************************/
/******* UNDER SUPERVISION OF ENG. KEROLES SHENOUDA****************************************************************/
/******* LEARN-IN-DEPTH********************************************************************************************/
/******* VERSION: 01***********************************************************************************************/

#ifndef INCLUDES_GPIO_H_
#define INCLUDES_GPIO_H_

//-----------------------------
//Includes
//-----------------------------
#include "../../STM32F103C6x COTS/INCLUDES/STM32F103C6xx.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{
	uint8_t PIN_NUM;
	uint8_t PIN_MODE;
	uint8_t PIN_OUTPUT_SPEED;
}s_GPIO_PIN_CONFIG_t;

#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

//====================================
//	CNF BITS
//====================================
#define MCAL_GPIO_ANALOG		(uint8_t)0
#define MCAL_GPIO_FLO_IN		(uint8_t)1
#define MCAL_GPIO_PU_IN			(uint8_t)2
#define MCAL_GPIO_PD_IN			(uint8_t)3

#define MCAL_GPIO_GPO_PP		(uint8_t)4
#define MCAL_GPIO_GPO_OD		(uint8_t)5
#define MCAL_GPIO_AFO_PP		(uint8_t)6
#define MCAL_GPIO_AFO_OD		(uint8_t)7

//====================================
//	MODE BITS
//====================================

#define MCAL_GPIO_INPUT			(uint8_t)0
#define MCAL_GPIO_OUT_10MHZ		(uint8_t)1
#define MCAL_GPIO_OUT_2MHZ		(uint8_t)2
#define MCAL_GPIO_OUT_50MHZ		(uint8_t)3

//-----------------------------
//Macros Configuration References
//-----------------------------



/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_vid_GPIO_INIT(s_GPIO_t* GPIOx , s_GPIO_PIN_CONFIG_t* PIN_CONFIG);

void MCAL_vid_GPIO_RESET(s_GPIO_t* GPIOx);

void MCAL_vid_WRITE_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO, uint8_t PIN_VAL);

void MCAL_vid_WRITE_PORT(s_GPIO_t* GPIOx, uint16_t PORT_VAL);

uint8_t MCAL_uint8_GPIO_READ_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO);

uint16_t MCAL_uint8_GPIO_READ_PORT(s_GPIO_t* GPIOx);

void MCAL_vid_TOGGLE_PIN(s_GPIO_t* GPIOx, uint8_t PIN_NO);

#endif /* INCLUDES_GPIO_H_ */
