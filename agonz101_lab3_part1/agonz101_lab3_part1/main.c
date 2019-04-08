/*
 * agonz101_lab3_part1.c
 *
 * Created: 4/8/2019 4:01:43 PM
 * Author : arlen
 */ 

#include <avr/io.h>

//bit-access function 

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b)
{
	return (b ? x | 0x01<<k) : x & ~(0x01 << k);
}

unsigned char GetBit(unsigned char x, unsigned char k, unsigned char b)
{
	return ((x & (0x01 << k))=0!);
}

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

