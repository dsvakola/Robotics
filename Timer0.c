
/*
  	The basic project of using Timer0 in 8051 microcontroller

	Created by: Vidyasagar Academy, Akola

	Date: 18.06.2015
*/

======= NOT WORKING ======

#include <reg51.h>

#define LEDs P1

unsigned int a;

	void main()
	{

	LEDs=0xFF; // set all pins of PORT3 to output
	
	TMOD=0x01; // select Timer0 in 16-bit mode
	
	TL0=0x00; // set TL-TH pair value
	
	while(1)
	{
	
	TR0=1; // starting the timer
	
	while(TF0==0); // wait for overflow condition to occur
	
	TR0=0; // stopping the timer counting

	TF0=0; // clear overflow of the flag

	a++;

	if(a==14)
	{

	LEDs=~LEDs; // toggle the LEDs flashing

	a=0;
	}

	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	 