/*
 * RCC.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Omar_
 */

#ifndef _RCC_H_
#define _RCC_H_


//uint32_t MCAL_uint32Get


#define AHB 	0
#define APB1 	1
#define APB2 	2
#define HSE_CLK		(uint32_t)16000000
#define HSI_RC_CLK	(uint32_t)8000000
// We need to read PCLK1 and PCLK2 for the UART driver

// Thus, we need to implement some apis for returning the clock values






//===============================================
//
//	RCC APIs Prototypes
//
//===============================================

void RCC_vidEnablePeripheralClock(uint8_t cpy_u8BusId, uint8_t cpy_u8PerId);
void RCC_vidDisablePeripheralClock(uint8_t cpy_u8BusId, uint8_t cpy_u8PerId);


// Depending on HSI Clock Configurations:

uint32_t MCAL_RCC_GET_PCLK1(void);
uint32_t MCAL_RCC_GET_PCLK2(void);
uint32_t MCAL_RCC_GET_HCLK(void);
uint32_t MCAL_RCC_GET_SYS_CLK(void);



#endif /* INCLUDES_RCC_H_ */
