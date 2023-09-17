/******************************************************************************************************************/
/******* DRIVER: GPIO**********************************************************************************************/
/******* MCU: STM32F103C6x*****************************************************************************************/
/******* AUTHOR: OMAR MOHAMMAD MOSTAFA*****************************************************************************/
/******* UNDER SUPERVISION OF ENG. KEROLES SHENOUDA****************************************************************/
/******* LEARN-IN-DEPTH********************************************************************************************/
/******* VERSION: 01***********************************************************************************************/

#ifndef INCLUDES_STM32F103C6X_GPIO_H_
#define INCLUDES_STM32F103C6X_GPIO_H_

//-----------------------------
//Includes
//-----------------------------
#include"STM32F103C6xx.h"


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
#define MCAL_GPIO_ANALOG		0
#define MCAL_GPIO_FLO_IN		1
#define MCAL_GPIO_PU_IN			2
#define MCAL_GPIO_PD_IN			3

#define MCAL_GPIO_GPO_PP		4
#define MCAL_GPIO_GPO_OD		5
#define MCAL_GPIO_AFO_PP		6
#define MCAL_GPIO_AFO_OD		7

//====================================
//	MODE BITS
//====================================

#define MCAL_GPIO_INPUT			0
#define MCAL_GPIO_OUT_10MHZ		1
#define MCAL_GPIO_OUT_2MHZ		2
#define MCAL_GPIO_OUT_50MHZ		3

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

#endif /* INCLUDES_STM32F103C6X_GPIO_H_ */
