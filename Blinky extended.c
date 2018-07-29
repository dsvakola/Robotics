
/*
  	Code of blinking LEDs Extended code

	Created by: Vidyasagar Academy, http://vsagar.org 

	Date: 10.12.2016

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

#include <reg51.h> // registry head file included
#include "delay.c" // including the .c file for user defined delay function
#define LEDs P1 // assigning the PORT1 to 8 LEDs

	int main() // main function
	{ // main function brace opened
	
	P1=0x00;
	delay(1000); // momentary delay to keep all LEDs OFF initially

	int a; // variable for "for" loop

	while(1) // infinite loop
	{ // while loop brace opened

	for(a=0;a<4;a++)
	{
	LEDs=~LEDs; // all LEDs flash	
	delay(500); 
	}

	for(a=0;a<4;a++)
	{
	LEDs=0x81; 	
	delay(500); 
	LEDs=0x42; 	
	delay(500); 
	LEDs=0x24; 	
	delay(500); 
	LEDs=0x18; 	
	delay(500); 
	LEDs=0x00; 	
	delay(500); 
	}

	for(a=0;a<4;a++)
	{
	LEDs=0x81; 	// 1000 0001
	delay(300); 
	LEDs=0xC3; 	// 1100 0011
	delay(300); 
	LEDs=0xE7; 	// 1110 0111
	delay(300); 
	LEDs=0xFF; 	// 1111 1111
	delay(300); 
	LEDs=0xE7; 	// 1110 0111
	delay(300); 
	LEDs=0xC3; 	// 1100 0011
	delay(300); 
	LEDs=0x81; 	// 1000 0001
	delay(300); 
	LEDs=0x00; 	
	delay(300); 
	}

	for(a=0;a<4;a++)
	{
	LEDs=0x81; 	// 1000 0001
	delay(500); 
	LEDs=0xC3; 	// 1100 0011
	delay(500); 
	LEDs=0xE7; 	// 1110 0111
	delay(500); 
	LEDs=0xFF; 	// 1111 1111
	delay(500); 
	LEDs=0x00; 	
	delay(500); 
	}

	} // while loop closed

	} // main closed