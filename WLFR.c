
/*
  	Program of White line following robot

	Created by: VIDYASAGAR ACADEMY, http://vsagar.org/

	Date: 26.04.2017

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***
*/

#include <reg51.h> // including header file
#define motors P1 // PORT1 is assigned to "motors"
sbit LS=P3^7; // left IR sensor is connected to pin-7 of PORT3
sbit RS=P3^0; // right IR sensor is connected to pin-0 of PORT3

/* 	==== IMPORTANT NOTE =====
	When there is black below an IR sensor, its output is binary-1
	When there is white below an IR sensor, its output is binary-0

	***** This code is suitable for OVAL SHAPED SIMPLE BLACK TRACKS *****
	***** For complicated black tracks USE POWER TURN INSTEAD OF SOFT TURN *****
*/ 
	
	int main() // main function
	{ // opening brace of main function

	while(1) // infinite loop
	{ // opening brace of while loop

	if((LS==1)&(RS==1)) // both sensors are on black
	{
	motors=0x09; // forward
	}

	if((LS==0)&(RS==0)) // both sensors are on white 
	{
	motors=0x00; // stop
	}

	if((LS==0)&(RS==1)) // only LS is on white
	{
	motors=0x01; // soft left turn (***** Refer above note)
	}

	if((LS==1)&(RS==0)) // only RS is on white
	{
	motors=0x08; // soft right turn (***** Refer above note)
	}

	} // while closed
	} // main function closed