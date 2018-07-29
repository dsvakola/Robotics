
/*
  	7 Segment (Common Cathode) LED Display using 8051 Code
	Created by: VIDYASAGAR ACADEMY, http://vsagar.org/
	Date: 26.04.2017

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

/*
  	==== 
		To use this code, fix a Common Cathode type 7-segment LED display
		on a breadboard and connect its pins to PORT2 in following sequence 
		P2^0 - a, P2^1 - b, P2^2 - c, P2^3 - d, P2^4 - e, P2^5 - f, P2^6 - g
		and then connect the GROUND terminal of the display to 
		-ve terminal of your dev. board.

		**** P2^7 should be left open ****
	====
*/
	
#include <reg51.h> // reg52 header file included
#include "delay.c" // customised delay file included
#define Display P2 // PORT2 is assigned to 'Display'

	void main()	// main function started
	{ // opening brace of main function

	int i; // variable for counting 10 cases
	Display=0xFF; // display shows '8' initially
	delay(200);

	while(1)
	{
	for(i=0;i<11;i++)
	{
	delay(50);
			
/*
	PORT1 pins -->           7    6    5    4    3    2    1    0  	
	7-seg. display pins -->	 X    g	   f	e	 d	  c	   b	a
*/
				

	switch(i)
	{
		case 0: 
		Display=0x3F; // '0' is dispalyed
		break;

		case 1:
		Display=0x06; // '1' is dispalyed
		break;

		case 2:
		Display=0x5B; // '2' is dispalyed
		break;

		case 3:
		Display=0x4F; // '3' is dispalyed
		break;

		case 4:
		Display=0x66; // '4' is dispalyed
		break;

		case 5:
		Display=0x6D; // '5' is dispalyed
		break;

		case 6:
		Display=0x7D; // '6' is dispalyed
		break;

		case 7:
		Display=0x07; // '7' is dispalyed
		break;

		case 8:
		Display=0x7F; // '8' is dispalyed
		break;

		case 9:
		Display=0x6F; // '9' is dispalyed
		break;
	} // switch closed
	} // 'for' loop closed

	} // while closed
	} // main function closed

