#include<stdio.h>
#include"Platform_Types.h"

#define RCC_BASE 		0x40021000
#define PORT_A_BASE		0x40010800

#define RCC_APB2ENR		*(v_uint32_t*)(RCC_BASE 	+ 0x18)		/* Bit 2 should be set to enable clock for GPIO peripheral*/
#define GPIO_CRH		*(v_uint32_t*)(PORT_A_BASE 	+ 0x04)		/* Control register which we need to set our port OUTPUT*/
#define GPIOA_ODR		*(v_uint32_t*)(PORT_A_BASE 	+ 0x0C)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/

typedef union{
	v_uint32_t ALL_PINS;
	struct{
		v_uint32_t PIN_0:1;
		v_uint32_t PIN_1:1;
		v_uint32_t PIN_2:1;
		v_uint32_t PIN_3:1;
		v_uint32_t PIN_4:1;
		v_uint32_t PIN_5:1;
		v_uint32_t PIN_6:1;
		v_uint32_t PIN_7:1;
		v_uint32_t PIN_8:1;
		v_uint32_t PIN_9:1;
		v_uint32_t PIN_10:1;
		v_uint32_t PIN_11:1;
		v_uint32_t PIN_12:1;
		v_uint32_t PIN_13:1;
		v_uint32_t PIN_14:1;
		v_uint32_t PIN_15:1;
		v_uint32_t PIN_16:1;
		v_uint32_t PIN_17:1;
		v_uint32_t PIN_18:1;
		v_uint32_t PIN_19:1;
		v_uint32_t PIN_20:1;
		v_uint32_t PIN_22:1;
		v_uint32_t PIN_23:1;
		v_uint32_t PIN_24:1;
		v_uint32_t PIN_25:1;
		v_uint32_t PIN_26:1;
		v_uint32_t PIN_27:1;
		v_uint32_t PIN_28:1;
		v_uint32_t PIN_29:1;
		v_uint32_t PIN_30:1;
		v_uint32_t PIN_31:1;
	}PINS;
}GPIO_ODR;
/*Create pointer to union and set adress to actual peripheral location*/
volatile GPIO_ODR* GPIO_ODR_PTR = (volatile GPIO_ODR*)(PORT_A_BASE 	+ 0x0C) ;

void main()
{
	volatile int i;
	RCC_APB2ENR |= 1<<2;		/*Enable clock for GPIO*/
	GPIO_CRH &= 0xFF0FFFFF;		/*	Make control for PortA out*/
	GPIO_CRH |= 0x00200000;
    /* Loop forever */
	while(1)
	{
		GPIO_ODR_PTR->PINS.PIN_13 =1;
		for(i=0;i<5000;i++);
		GPIO_ODR_PTR->PINS.PIN_13 =0;
		for(i=0;i<5000;i++);
	}
}
