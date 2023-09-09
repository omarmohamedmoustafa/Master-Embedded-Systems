#include"stdint.h"
void GPIO_vid_Init();
void RCC_vid_Init();
void EXTI_vid_Init();


#define GPIO_A_BASE		0x40010800

/*RCC Private*/
#define RCC_BASE 		0x40021000
#define RCC_APB2ENR		*(volatile uint32_t*)(RCC_BASE 	+ 0x18)		/* Bit 2 should be set to enable clock for GPIO peripheral*/


/*GPIO Private*/
#define GPIOA_CRH		*(volatile uint32_t*)(GPIO_A_BASE 	+ 0x04)		/* Control register which we need to set our port OUTPUT*/
#define GPIOA_ODR		*(volatile uint32_t*)(GPIO_A_BASE 	+ 0x0C)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/
#define GPIOA_CRL		*(volatile uint32_t*)(GPIO_A_BASE 	+ 0x00)		/* Control register which we need to set our port OUTPUT*/

#define AFIO_BASE 		0x40010000
#define AFIO_EXTICR1		*(volatile uint32_t*)(AFIO_BASE + 0x08)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/

#define EXTI_BASE 		0x40010400
#define EXTI_IMR			*(volatile uint32_t*)(EXTI_BASE + 0x00)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/
#define EXTI_RTSR			*(volatile uint32_t*)(EXTI_BASE + 0x08)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/
#define EXTI_PR				*(volatile uint32_t*)(EXTI_BASE + 0x14)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/

#define NVIC_ISER0			*(volatile uint32_t*)(0xE000E100)		/* OUTPUT DATA REGISTER to be toggled in pin 13	*/


void GPIO_vid_Init()
{
	GPIOA_CRH 		&= 0xFF0FFFFF;		/*	Make control for PortA out*/
	GPIOA_CRH 		|= 0x00200000;
	GPIOA_CRL 		|= 1<<2;
	AFIO_EXTICR1	|= 0000<<0;
}

void RCC_vid_Init()
{
	RCC_APB2ENR |= 1<<2;		/*Enable clock for GPIO PORT A*/
	RCC_APB2ENR |= 1<<0;		/*Enable clock for AFIO*/
}
void EXTI_vid_Init()
{
	EXTI_IMR 	|= 	1<<0;
	EXTI_RTSR 	|=	1<<0;
}

int main()
{
	RCC_vid_Init();
	GPIO_vid_Init();
	EXTI_vid_Init();
	NVIC_ISER0 |=1<<6;
    /* Loop forever */
	while(1);
	return 0;
}
void EXTI0_IRQHandler()
{
	EXTI_PR		|=	1<<0;
	GPIOA_ODR ^= 1<<13;
}
