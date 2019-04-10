/*
 * agonz101_lab3_part1.c
 *
 * Created: 4/8/2019 4:01:43 PM
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's and B's 8 pins as inputs
	DDRB =0x00; PORTB =0xFF;
	
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
	
	unsigned char NumberofOnes =0x00; //used to store the number of 1's
	unsigned char GetA=0x00; //stores what is in port a and b
	unsigned char GetB=0x00;
	
	
	while(1)
	{
		GetA=PINA;// set them equal to the ports
		GetB=PINB;
		
		for(int i=0;i<8;i++)// for loop to get the the bits that are one;
		{
			
			if (GetBit(GetA, i)==1)//get all the a
			{ 
				NumberofOnes=NumberofOnes+1;
			}
			if (GetBit(GetB, i)==1) //get all the b
			{
				NumberofOnes=NumberofOnes+1;
			}
		}
			
		PORTC = NumberofOnes //set it equal and set counter to zero
		NumberofOnes=0;
		
	}
}


