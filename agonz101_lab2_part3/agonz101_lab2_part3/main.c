/*
 * agonz101_lab2_part3.c
 *
 * Created: 4/7/2019 8:23:47 PM
 * Author : arlen
 */ 

#include <avr/io.h>


int main(void)
{
	/* Replace with your application code */
	//declare the input and output ports
	DDRA =0x00;	PORTA=0xFF;
	DDRC=0xFF; PORTC=0x00;
	//create temp values
	unsigned char Parking1=0x00;
	unsigned char Parking2=0x00;
	unsigned char Parking3=0x00;
	unsigned char Parking4=0x00;
	unsigned char tempB=0x00;
	unsigned char count=0x00;
	
	while (1)
	{
		//cancel all other numbers after each location to get parking
		Parking1= PINA & 0x01;//checks if parking in 1 {0001}
		Parking2= PINA & 0x02;//checks if parking in 1 {0011} or {0010}
		Parking3= PINA & 0x04;//checks if parking in 1 {0111} or {0110} or {0101} or {0100}
		Parking4= PINA & 0x08;//checks if parking in 1 {1111} or {1110} or {1101} or {1100} {1011} or {1010} or {1001} or {1000}
		
		if(Parking1==0x01)//checks parking  and is so ++count for taken parking
		{
			count=count+1;
		}
		if(Parking2==0x02)
		{
			count=count+1;
		}
		if(Parking3==0x04)
		{
			count=count+1;
		}
		if(Parking4==0x08)
		{
			count=count+1;
		}
		//based on count determines the parking left
		switch (count) {
			case 1:
			tempB = 0x03;
			break;
			case 2:
			tempB = 0x02;
			break;
			case 3:
			tempB = 0x01;
			break;
			case 4:
			tempB = 0x40; //changes to pin 7 equal to 1 if full
			break;
			default:
			tempB = 0x40; //changes to pin 7 equal to 1 if full
			break;
		}
		//sets Portc to temp and sets count to 0 to count again
		PORTC=tempB;
		count=0;
		
	}
}



