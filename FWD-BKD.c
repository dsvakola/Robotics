
/*
	8051 Forward backward motion of robot
	Created by: Prof. Dattaraj Vidyasagar 
	for Vidyasagar Academy, Akola
	Website: http://vsagar.og/
	
	Date: 26.04.2017
*/

#include <reg51.h>
#include "delay.c"


	int main()
	{

	P1=0x00;  // this will keep all outputs of PORT1 to 0000 0000 initially
	delay(1); // momentary delay

	while(1) // infinite loop
	{
	P1=0x09;
	delay(3000);
	P1=0x06;
	delay(3000)	

	} // while closed

	} // main closed