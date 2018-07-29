
/*
  	Code of blinking LEDs

	Created by: Vidyasagar Academy, Akola; http://vsagar.org 

	Date: 25.04.2017

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

#include <reg51.h> // registry head file included
#include "delay.c" // including the .c file for user defined delay function
#define LEDs P1 // assigning the PORT1 to 8 LEDs

	int main() // main function

	{ // main function brace opened

	while(1) // infinite loop

	{ // while loop brace opened

	LEDs=0x0F; // all outputs of PORT1 = 1	
	delay(1000); // delay of 1 sec.

	LEDs=0x00; // all outputs of PORT1 = 0	
	delay(1000); // delay of 1 sec.

	LEDs=0xF0; // all outputs of PORT1 = 1	
	delay(1000); // delay of 1 sec.

	LEDs=0x00; // all outputs of PORT1 = 0	
	delay(1000); // delay of 1 sec.

	} // while loop closed

	} // main closed