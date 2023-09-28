#include "STM32F103C6xx.h"
#include "UART.h"
#include "GPIO.h"
#include "RCC.h"
s_USART_Config_t* Global_USARTx_Config;
void MCAL_UART_INIT(s_USART_t* USARTx , s_USART_Config_t* USARTx_Config)
{
	Global_USARTx_Config = USARTx_Config;
	uint32_t Pclk;
	// Enable RCC clock for usart
	if(USARTx == USART1)
		MCAL_RCC_ENABLE_USART1();
	else if(USARTx == USART2)
		MCAL_RCC_ENABLE_USART2();
	else if(USARTx == USART2)
		MCAL_RCC_ENABLE_USART3();

	// Enable UE Bit in CR1 in USARTx

	SET_BIT(USARTx->CR1,13);

	// Set Mode according to user specifications

	USARTx->CR1 |= USARTx_Config->USART_MODE;

	// Set Word Length

	USARTx->CR1 |= USARTx_Config->PAYLOAD;

	// Set Parity Configuration

	USARTx->CR1 |= USARTx_Config->PARITY;

	// Set IRQ Configuration

	USARTx->CR1 |= USARTx_Config->IRQ_ENABLE;

	if(USARTx == USART1)
		MCAL_NVIC_USART1_IRQ37_ENABLE();
	else if(USARTx == USART2)
		MCAL_NVIC_USART2_IRQ38_ENABLE();
	else if(USARTx == USART3)
		MCAL_NVIC_USART3_IRQ39_ENABLE();

	// Set Stop bits Configuration
	USARTx->CR2 |= USARTx_Config->STOP_BITS;

	// Set Flow Control

	USARTx->CR3 |= USARTx_Config->FLOW_CTRL;

	// Set Baud Rate
	if(USARTx == USART1)
		Pclk = MCAL_RCC_GET_PCLK2();
	else
		Pclk = MCAL_RCC_GET_PCLK1();

	USARTx->BRR |= USART_BRR(Pclk, USARTx_Config->BAUD_RATE);

}
void MCAL_UART_DEINIT(s_USART_t* USARTx)
{
	// CLR IRQ Enable
	if(USARTx == USART1)
	{
		MCAL_NVIC_USART1_IRQ37_DISABLE();
		MCAL_RCC_DISABLE_USART1();
	}
	else if(USARTx == USART2)
	{
		MCAL_NVIC_USART2_IRQ38_DISABLE();
		MCAL_RCC_DISABLE_USART2();
	}
	else if(USARTx == USART3)
	{
		MCAL_NVIC_USART3_IRQ39_DISABLE();
		MCAL_RCC_DISABLE_USART3();
	}


}
void MCAL_UART_SND_DATA(s_USART_t* USARTx , uint16_t* USART_Tx_DATA , IR_POLLING PollingReq)
{
	if(PollingReq == Enable)
		while(!((USARTx->SR >> 7) & (0b1))); // Wait untill Tx Data register is empty
	if(Global_USARTx_Config->PAYLOAD == USART_PAYLOAD_9BITS)
		USARTx->DR = (*USART_Tx_DATA &(uint16_t)(0x1FF));
	else if(Global_USARTx_Config->PAYLOAD == USART_PAYLOAD_8BITS)
		USARTx->DR = (*USART_Tx_DATA &(uint8_t)(0xFF));
}
void MCAL_UART_WAIT_TxCOMPLETE(s_USART_t* USARTx)
{
	while(   ((USARTx->SR >> 6) & (0b1)) == 0);
}
void MCAL_UART_RCV_DATA(s_USART_t* USARTx , uint16_t* USART_Tx_DATA , IR_POLLING PollingReq)
{
	if(PollingReq == Enable)
		while(	((USARTx->SR >> 5) & (0b1)) == 0);
	if(Global_USARTx_Config->PAYLOAD == USART_PAYLOAD_9BITS)
	{
		if(Global_USARTx_Config->PARITY == USART_PARITY_OFF)
		{
			*((uint16_t*)USART_Tx_DATA) = USARTx->DR;
		}
		else
		{
			*((uint16_t*)USART_Tx_DATA) = (USARTx->DR) & (uint8_t)0xFF;
		}
	}
	else
	{
		if(Global_USARTx_Config->PARITY == USART_PARITY_OFF)
		{
			*((uint16_t*)USART_Tx_DATA) = (USARTx->DR) & (uint8_t)0xFF ;
		}
		else
		{
			*((uint16_t*)USART_Tx_DATA) = (USARTx->DR) & (uint8_t)0x7F;
		}
	}
}
void MCAL_UART_GPIO_SET_PINS(s_USART_t* USARTx)
{

	// Watch Recommended settings from GPIO Part in stm32f103xx TRM
	// UART pin configuration recommended settings
	s_GPIO_PIN_CONFIG_t PinCGF;
	if(USARTx == USART1)
	{
		//PA9  --> Tx
		//PA10 --> Rx
		//PA11 --> CTS
		//PA12 --> RTs
		//======================================================
		PinCGF.PIN_NUM=9;
		PinCGF.PIN_MODE= MCAL_GPIO_AFO_PP;
		PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_OUT_10MHZ;
		MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
		//======================================================
		PinCGF.PIN_NUM=10;
		PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
		PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
		MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
		//======================================================
		if(Global_USARTx_Config->FLOW_CTRL == USART_CTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
		{
			PinCGF.PIN_NUM=11;
			PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
		}
		//======================================================
		if(Global_USARTx_Config->FLOW_CTRL == USART_RTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
		{
			PinCGF.PIN_NUM=12;
			PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
		}
	}
	else if(USARTx == USART2)
	{
		if(USARTx == USART1)
		{
			//PA2  --> Tx
			//PA3 --> Rx
			//PA0 --> CTS
			//PA1 --> RTs
			//======================================================
			PinCGF.PIN_NUM=2;
			PinCGF.PIN_MODE= MCAL_GPIO_AFO_PP;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_OUT_10MHZ;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			//======================================================
			PinCGF.PIN_NUM=3;
			PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			//======================================================
			if(Global_USARTx_Config->FLOW_CTRL == USART_CTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
			{
				PinCGF.PIN_NUM=0;
				PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
				PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
				MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			}
			//======================================================
			if(Global_USARTx_Config->FLOW_CTRL == USART_RTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
			{
				PinCGF.PIN_NUM=1;
				PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
				PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
				MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			}
		}
	}
	else
	{
		if(USARTx == USART1)
		{
			//PB10  --> Tx
			//PB11  --> Rx
			//PB13  --> CTS
			//PB14  --> RTs
			//======================================================
			PinCGF.PIN_NUM=10;
			PinCGF.PIN_MODE= MCAL_GPIO_AFO_PP;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_OUT_10MHZ;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			//======================================================
			PinCGF.PIN_NUM=11;
			PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
			PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
			MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			//======================================================
			if(Global_USARTx_Config->FLOW_CTRL == USART_CTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
			{
				PinCGF.PIN_NUM=13;
				PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
				PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
				MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			}
			//======================================================
			if(Global_USARTx_Config->FLOW_CTRL == USART_RTS_ENABLE || Global_USARTx_Config->FLOW_CTRL == USART_CTS_RTS_ENABLE)
			{
				PinCGF.PIN_NUM=14;
				PinCGF.PIN_MODE= MCAL_GPIO_FLO_IN;
				PinCGF.PIN_OUTPUT_SPEED=MCAL_GPIO_INPUT;
				MCAL_vid_GPIO_INIT(GPIOA, &PinCGF);
			}
		}
	}
}
void USART1_IRQHandler (void)
{
	Global_USARTx_Config->P_IRQ_CALLBACK();
}
void USART2_IRQHandler (void)
{
	Global_USARTx_Config->P_IRQ_CALLBACK();
}
void USART3_IRQHandler (void)
{
	Global_USARTx_Config->P_IRQ_CALLBACK();
}
