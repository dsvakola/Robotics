
/*
  	Program of Obstacle avoiding robot

	Created by: VIDYASAGAR ACADEMY, http://vsagar.org/

	Date: 26.04.2017

	*** Please respect our efforts 
	and write Google review about Vidyasagar Academy, Akola. ***

*/

#include <reg52.h> // including header file
#include "delay.c" // including the customised delay file
#define motors P1 // PORT1 is assigned to "motors"
sbit LS=P0^7; // left IR sensor is connected to pin-7 of PORT0
sbit RS=P0^0; // right IR sensor is connected to pin-0 of PORT0

/* 	==== IMPORTANT NOTE =====
	When there is black below an IR sensor, its output is binary-1
	When there is white below an IR sensor, its output is binary-0

	***** Both IR sensors are fitted vertically in this project. *****

	*** YOU MUST CHANGE THE DELAY TIMING AS PER YOUR REQUIREMENT ***
*/ 
	
	int main() // main function
	{ // opening brace of main function

	while(1) // infinite loop
	{ // opening brace of while loop

	if((LS==1)&(RS==1)) // no obstacle in front of both sensors
	{
	motors=0x09; // forward
	}

	if((LS==0)&(RS==0)) // obstacle detected in front of BOTH SENSORS
	{
	motors=0x00; // stop
	delay(200);
	motors=0x06; // backward
	delay(170);
	motors=0x0A; // power right turn (*** You can give power left turn also)
	delay(50);
	}

	if((LS==1)&(RS==0)) // obstacle detected in front of RS
	{
	motors=0x00; // stop
	delay(200);
	motors=0x06; // backward
	delay(170);
	motors=0x0A; // power right turn
	delay(50);
	}

	if((LS==0)&(RS==1)) // obstacle detected in front of LS
	{
	motors=0x00; // stop
	delay(200);
	motors=0x06; // backward
	delay(170);
	motors=0x05; // power left turn
	delay(50);
	}

	} // while closed
	} // main function closed