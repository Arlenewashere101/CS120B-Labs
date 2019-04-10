/*
 * GccApplication2.c
 *
 * Created: 4/9/2019 8:23:36 PM
 * Author : arlen
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
	
	while(1)
	{
		fuelValue=PINA;// set them equal to the ports
		
		
		//checks for fuel range 1-15
		for(unsigned char i=1;i<16;i)
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

		
		
		PORTC = numberOfLEDS; //set it equal and set counter to zero
		numberOfLEDS=0;		//reset
		bitLocation=5;
	}
}

