
#include<avr/io.h>
#include<avr/delay.h>
#include"LIB/types.h"
#include "LIB/7SEG.h"
void main (void)
{
	DDRC = 0xff;
	DDRA = 0xff;
	DDRD = 0xff;
    u8 i=0;
    u8 ARR[10]={ZERO,NINE,EIGHT,SEVEN,SIX,FIVE,FOUR,THREE,TWO,ONE};
	u8 yellow;
    while(1)
	{
    	//GREEN
    		PORTD=0b00100100;
    		PORTA=ONE;

    		for(i=0;i<10;i++)
    			{
    			if(i>0)
    				{
    				PORTA=ZERO;
    				}
    			PORTC=ARR[i];
    			_delay_ms(1000);

    			}

    //YELLOW
    		PORTD=0b01001010;
    		for(yellow=7;yellow<10;yellow++)
    		{
    			PORTC=ARR[yellow];
    			_delay_ms(1000);
    		}
    	//RED
    	PORTD=0b10110001;
		PORTA=ONE;
		for(i=0;i<10;i++)
		{
			if(i>0)
			{
			PORTA=ZERO;
			}
			PORTC=ARR[i];
			_delay_ms(1000);

		}

	}
}

//
