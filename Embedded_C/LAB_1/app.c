#include"stdio.h"
#include"uart.h"
uint8_t string [50]="Learn In Depth <OMAR>";
void main()
{
	uart_send_txt(string);
}