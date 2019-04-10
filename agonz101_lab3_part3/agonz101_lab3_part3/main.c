/*
 * agonz101_lab3_part3.c
 *
 * Created: 4/10/2019 11:46:08 AM
 * Author : arlen
 */ 

/*	arlene gonzalez agonz101@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #3 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Fuel Sensor: Configure port A's and B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; //LEDS: Configure port C's 8 pins as outputs,
	
	
	unsigned char fuelValue=0x00; //stores what is in port a and b
	unsigned char numberOfLEDS=0x00;
	unsigned char bitLocation=0x05;
	unsigned char Safety =0x00;

	
	while(1)
	{
		fuelValue=PINA & 0x0F;
		
		Safety=PINA;
		
		//checks for fuel range 1-15
			for(unsigned char i=1;i<16;)
			{
			
				if (fuelValue<7)//if fuel less then 7 increment by 2
				{
					if(fuelValue>=i)//if fuel is greater than i turn that LED
					{
						numberOfLEDS=SetBit(numberOfLEDS, bitLocation, 1);
					}
					else//exit loop
					{
						i=16;
					}
					i=i+2;
				}
			
				else //if fuel range 7 or higher and increment by 3
				{
				
					if(i==1) //in the beginning turn LED 5-3 and change i and bitLocation
					{
						i=7;
						numberOfLEDS=SetBit(numberOfLEDS, 5, 1);
						numberOfLEDS=SetBit(numberOfLEDS, 4, 1);
						numberOfLEDS=SetBit(numberOfLEDS, 3, 1);
						bitLocation=2;
					}

				
				
					if(fuelValue>=i)//if greater than value i turn on LED
					{
						numberOfLEDS=SetBit(numberOfLEDS, bitLocation, 1);
					}
					else //exit
					{
						i=16;
					}
					i=i+3;
				}

			
				bitLocation=bitLocation-1; //change bit location
			
			}
		
		//only of key in in, person is seated, but doesn't have seatbelt Turn LED 7 on
		if( GetBit(Safety,4)==1 )//&& GetBit(Safety,5)==1 &&  GetBit(Safety,4)==0)
		{
			if( GetBit(Safety,5)==1) 
			{
				if(  GetBit(Safety,6)==0)
				{
					numberOfLEDS=SetBit(numberOfLEDS, 7, 1);
				}
			}
		
		}
		
		PORTC = numberOfLEDS; //set it equal and set counter to zero
		numberOfLEDS=0;		//reset
		bitLocation=5;
	}
}
