#include<avr/io.h>
#include<avr/delay.h>
#include"LIB/types.h"

void main (void)
{
	u8 i =0;
	DDRD=0xff;


	while(1)
	{
		for(i=0;i<7;i++)
				{
							PORTD|=0xff;
							_delay_ms(200);
							PORTD&=0x00;
							_delay_ms(200);


				}

		for(i=8;i>0;i--)
		{
					PORTD = 1<<i;
					_delay_ms(150);
		}

		for(i=0;i<7;i++)
		{
					PORTD = 1<<i;
					_delay_ms(150);
		}



		for(i=0;i<7;i++)
		{
					PORTD |= 1<<i;
					_delay_ms(200);


		}

		for(i=0;i<7;i++)
				{
					PORTD &=~ 1<<i;
										_delay_ms(200);
				}

	}
}
