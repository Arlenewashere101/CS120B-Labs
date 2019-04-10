/*
 * agonz101_lab2_part4.c
 *
 * Created: 4/7/2019 10:36:15 PM
 * Author : arlen
 */ 

#include <avr/io.h>


int main(void)
{
	/* Replace with your application code */
	//declare the input and output ports
	DDRA =0x00;	PORTA=0xFF;
	DDRB =0x00;	PORTB=0xFF;
	DDRC =0x00;	PORTC=0xFF;
	
	DDRD=0xFF; PORTD=0x00;
	//create temp values
	unsigned char tempD=0x00;
	unsigned char actualWeightTotal=0x00;
	unsigned char shiftWeightTotal=0x00;
	unsigned char differenceA_C=0x00;
	unsigned char Bit0=0x00;
	unsigned char Bit1=0x00;
	
	
	while (1)
	{

		
		//gets the weights need to be compared
		actualWeightTotal=PINA+PINB+PINC;
		if(PINA>PINC)
		{
			differenceA_C=PINA-PINC;
		}
		else
		{
			
			differenceA_C=PINC-PINA;
		}
		
		
		//compares the total weight to max
		if(actualWeightTotal>0x8C)
		{
			Bit0=0x01;
		}
		//compares the balanced weight
		if(differenceA_C>0x50)
		{
			Bit1=0x02;
		}
		//set D last bit correctly
		
		shiftWeightTotal=actualWeightTotal*8;
		if(Bit0==0x01)
		{
			if(Bit1==0x02)
			{
				shiftWeightTotal=shiftWeightTotal+0x03;
			}
			else
			{
				shiftWeightTotal=shiftWeightTotal+0x01;
			}
			
		}
		tempD=shiftWeightTotal;
		PORTD=tempD;		
	}
}

