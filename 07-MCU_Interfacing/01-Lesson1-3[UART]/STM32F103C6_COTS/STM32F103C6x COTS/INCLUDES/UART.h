/*
 * UART.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Omar_
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_


//===================================
//
//		Configurable Items
//
//===================================
typedef struct{
	uint8_t USART_MODE; // specify Tx , Rx Enable and Disable
						//@ref  UART_MODE_DEFINE

	uint8_t BAUD_RATE;	// specify baudrate
						// @ref UART_BAUD_RATE_DEFINE

	uint8_t PAYLOAD;    // specify 8 or 9 bits
						// @ref USART_PAYLOAD_DEFINE

	uint8_t PARITY;		// specify yparity type : even, odd , off
						// @ref USART_PARITY_DEFINE

	uint8_t STOP_BITS;	// specify number of needed stop bits
						// @ref USART_STOP_BITS_DEFINE

	uint8_t FLOW_CTRL;	// specify flow control status configuration
						// @ref USART_FLOW_CTRL_DEFINE

	uint8_t IRQ_ENABLE; // specify interrupt enable config
						// @ref USART_IRQ_ENABLE_DEFINE

	void (* P_IRQ_CALLBACK)(void);
}s_USART_Config_t;

typedef enum{
	Enable,
	Disable
}IR_POLLING;
//@ref  UART_MODE_DEFINE
#define USART_MODE_Rx_ON			((uint32_t)(1<<2))
#define USART_MODE_Tx_ON			((uint32_t)(1<<3))
#define USART_MODE_Rx_Tx_ON			((uint32_t)(1<<3) | (uint32_t)(1<<2))


// @ref UART_BAUD_RATE_DEFINE
#define USART_BR_2400				2400
#define USART_BR_9600				9600
#define USART_BR19200				19200
#define USART_BR_57600				57600
#define USART_BR_115200				115200
#define USART_BR_230400				230400
#define USART_BR_460800				460800
#define USART_BR_921600				921600
#define USART_BR_2250000			2250000
#define USART_BR_4500000			4500000

// @ref USART_PAYLOAD_DEFINE
#define USART_PAYLOAD_8BITS			((uint32_t)(0 << 12))
#define USART_PAYLOAD_9BITS			((uint32_t)(1 << 12))



// @ref USART_PARITY_DEFINE
#define USART_PARITY_EVEN				((uint32_t)( 0b10 <<  9 ))
#define USART_PARITY_ODD				((uint32_t)( 0b11 <<  9 ))
#define USART_PARITY_OFF				((uint32_t)( 0b00 <<  9 ))


// @ref USART_STOP_BITS_DEFINE
#define USART_STOP_BITS1			((uint32_t)(0b00<<12))
#define USART_STOP_BITS0_5			((uint32_t)(0b01<<12))
#define USART_STOP_BITS2			((uint32_t)(0b10<<12))
#define USART_STOP_BITS1_5			((uint32_t)(0b11<<12))


// @ref USART_FLOW_CTRL_DEFINE
#define USART_FLOW_CTRL_NONE		((uint32_t)(0))
#define USART_CTS_ENABLE			((uint32_t)(1<<9))
#define USART_RTS_ENABLE			((uint32_t)(1<<8))
#define USART_CTS_RTS_ENABLE    	((uint32_t)(0b11<<8))


// @ref USART_IRQ_ENABLE_DEFINE
#define USART_IRQ_ENABLE_PE			((uint32_t)(1<<8))
#define USART_IRQ_ENABLE_NONE		((uint32_t)(0))
#define USART_IRQ_ENABLE_TxEIE		((uint32_t)(1<<7))
#define USART_IRQ_ENABLE_TxCIE		((uint32_t)(1<<6))
#define USART_IRQ_ENABLE_RxNEIE		((uint32_t)(1<<5))



//BAUD RATE CALCULATION
#define USART_DIV(PCLK,BAUD)					(uint32_t)(PCLK/(16*BAUD))
#define USART_DIV_MUL_100(PCLK,BAUD)			(uint32_t)((25*PCLK)/(4*BAUD))
#define USART_DIV_MANTISSA_MUL_100(PCLK,BAUD)	(uint32_t)(USART_DIV(PCLK,BAUD)*100)
#define USART_DIV_MANTISSA(PCLK,BAUD)			(uint32_t)(USART_DIV(PCLK,BAUD))
#define USART_DIV_FRACTION(PCLK,BAUD)			(uint32_t)(((USART_DIV_MUL_100(PCLK,BAUD)-USART_DIV_MANTISSA_MUL_100(PCLK,BAUD))*16) / 100)
#define USART_BRR(PCLK,BAUD)					((USART_DIV_MANTISSA(PCLK,BAUD)) << 4) | ((USART_DIV_FRACTION(PCLK,BAUD)) & 0xF)

//===================================
//
//		Public APIs Prototypes
//
//===================================

void MCAL_UART_INIT(s_USART_t* USARTx , s_USART_Config_t* USARTx_Config);
void MCAL_UART_DEINIT(s_USART_t* USARTx);
void MCAL_UART_GPIO_SET_PINS(s_USART_t* USARTx);
void MCAL_UART_SND_DATA(s_USART_t* USARTx , uint16_t* USART_Tx_DATA , IR_POLLING PollingReq);
void MCAL_UART_RCV_DATA(s_USART_t* USARTx , uint16_t* USART_Tx_DATA , IR_POLLING PollingReq);
void MCAL_UART_WAIT_TxCOMPLETE(s_USART_t* USARTx);

#endif /* INCLUDES_UART_H_ */
