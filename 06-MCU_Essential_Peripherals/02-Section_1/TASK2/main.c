/*
 * main.c
 *
 * Created: 9/15/2023 9:00:06 AM
 *  Author: Omar_
 */ 
#define F_CPU 8000000UL
#include <xc.h>
#include "util/delay.h"
typedef unsigned char 		u8 ;
typedef unsigned short int	u16;
typedef unsigned long int 	u32;

#define PORTA_REG	 *((volatile u8*) 0x3B)
#define DDRA_REG 	 *((volatile u8*) 0x3A)
#define PINA_REG 	 *((volatile u8*) 0x39)

#define PORTB_REG  	 *((volatile u8*) 0x38)
#define DDRB_REG  	 *((volatile u8*) 0x37)
#define PINB_REG     *((volatile u8*) 0x36)

#define PORTC_REG  	 *((volatile u8*) 0x35)
#define DDRC_REG  	 *((volatile u8*) 0x34)
#define PINC_REG  	 *((volatile u8*) 0x33)

#define PORTD_REG  	 *((volatile u8*) 0x32)
#define DDRD_REG  	 *((volatile u8*) 0x31)
#define PIND_REG  	 *((volatile u8*) 0x30)

#define SET_BIT(reg,bit) 		reg |= (1<<(bit))
#define CLR_BIT(reg,bit)		reg &=~(1<<(bit))
#define GET_BIT(reg,bit)		((reg>>bit) & 1 )
#define TOG_BIT(reg,bit)		reg ^= (1<<(bit))


int main(void)
{
	
	DDRA_REG = 0xFF;
	CLR_BIT(DDRD_REG,0);
	SET_BIT(PORTD_REG,0);
	int count=0;
    while(1)
    {
		if(GET_BIT(PIND_REG,0)==0)
		{
			while(GET_BIT(PIND_REG,0)==0);
			TOG_BIT(PORTA_REG,count++);
		}
		if(count == 8)
			count =0;
    }
}