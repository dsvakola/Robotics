
/*
  	Program of Edge avoiding robot

	Created by: VIDYASAGAR ACADEMY, http://vsagar.org/

	Date: 26.04.2017

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

#include <reg51.h> // including header file
#include "delay.c" // including the customised delay file
#define motors P1 // PORT1 is assigned to "motors"
sbit LS=P3^7; // left IR sensor is connected to pin-7 of PORT3
sbit RS=P3^0; // right IR sensor is connected to pin-0 of PORT3

/* 	==== IMPORTANT NOTE =====
	When there is black below an IR sensor, its output is binary-1
	When there is white below an IR sensor, its output is binary-0
*/ 
	
	int main() // main function
	{ // opening brace of main function
		
		delay(5000); // introducting delay to avoid initial action of the robot

	while(1) // infinite loop
	{ // opening brace of while loop

	if((LS==0)&(RS==0)) // both sensors are on white
	{
	motors=0x09; // forward
	}

	if((LS==1)&(RS==1)) // both sensors are out of table edge
	{
	motors=0x00; // stop
	delay(1000);
	motors=0x06; // backward
	delay(600);
	motors=0x0A; // power right turn
	delay(400);
	}

	if((LS==1)&(RS==0)) // only LS is out of the edge
	{
	motors=0x00; // stop
	delay(1000);
	motors=0x06; // backward
	delay(600);
	motors=0x0A; // power right turn
	delay(400);
	}

	if((LS==0)&(RS==1)) // only RS is out of the edge
	{
	motors=0x00; // stop
	delay(1000);
	motors=0x06; // backward
	delay(600);
	motors=0x05; // power left turn
	delay(400);
	}

	} // while closed
	} // main function closed