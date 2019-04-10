/*	arlene gonzalez agonz101@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab # 3 Exercise # 4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    /* Replace with your application code */
	
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's pins as inputs
	
	DDRB =0xFF; PORTB =0x00;	
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's and C's 8 pins as outputs,
	
	unsigned char UpperNibble =0x00; //used to store the number of 1's
	unsigned char lowerNibble=0x00; //stores what is in port a and b
	
	
    while (1) 
    {
		UpperNibble=PINA;
		lowerNibble=PINA;
		
		for(unsigned char i=0;i<8;i++)// for loop to get the the bits that are one;
		{
			if(i<4)
			{
					UpperNibble=SetBit(UpperNibble, i, 0);
			}
			else
			{
					lowerNibble=SetBit(lowerNibble, i, 0);
			}
			
					
		}
		PORTB=UpperNibble;
		PORTC=lowerNibble;
}
}
