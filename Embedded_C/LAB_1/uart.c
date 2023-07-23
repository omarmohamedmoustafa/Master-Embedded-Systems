#include"uart.h"
#define UART0_DR *((v_uint32_t *)((uint32_t)0x101F1000))
void uart_send_txt (uint8_t *ptr_to_char)
{
	while(*ptr_to_char)
	{
		UART0_DR = (uint32_t)(*ptr_to_char);
		ptr_to_char++;
	}
}
