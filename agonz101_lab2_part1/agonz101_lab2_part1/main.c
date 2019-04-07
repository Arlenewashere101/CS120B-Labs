/*
 * agonz101_lab2_part1.c
 *
 * Created: 4/6/2019 6:46:18 PM
 * Author : arlen
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA=0x00; PORTA=0xFF;
	DDRB=0xFF; PORTB=0x00;
	
	unsigned char GarageAndLightSensor=0x00;
	unsigned char LightOperation=0x00;
    while (1) 
    {
		GarageAndLightSensor=PINA & 0x03;
		
		if(GarageAndLightSensor==0x01)
		{
			LightOperation=(LightOperation & 0xFC) | 0x01;
		}
		else
		{
			LightOperation=(LightOperation & 0xFC) | 0x00;
		}
		PORTB=LightOperation;
    }
	
	return 0;
}

