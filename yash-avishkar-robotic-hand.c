
/*
	Project of AT89S51 (8051 family) Gesture controlled robot arm
	Designed by: Yash Vidyasagar
	Date: 10.12.2017
	For Avishkar 2017-18 
*/

#include <reg51.h>
#include "delay.c"

#define CONTROL P1 // All 4 motors connected to 8 pins of PORT1

sbit d=P0^3;
sbit c=P0^2;
sbit b=P0^1;
sbit a=P0^0; // receiver's output signals connected to P0^3-P0^0

	int main()
	{

	P1=0x00;
	delay(1000); // perceptible pause to start the system smoothly

	while(1) // infinite loop
	{

	// Controlling signals for movement of robotic arm and gripper
	// Arm motor: P1^7(+) & P1^6(-)
	// Gripper motor: P1^5(+) & P1^4(-)

	if((d==1)&(c==1)&(b==0)&(a==0)) // S1 is pressed
	{
		CONTROL=0x80; // Arm moves up
	}

	if((d==0)&(c==0)&(b==1)&(a==1)) // S2 is pressed
	{
		CONTROL=0x40; // Arm moves down
	}

	if((d==1)&(c==0)&(b==0)&(a==0)) // S3 is pressed
	{
		CONTROL=0x20; // Gripper closes
	}

	if((d==0)&(c==0)&(b==0)&(a==1)) // S4 is pressed
	{
		CONTROL=0x10; // Gripper opens
	}


	// Controlling signals for movement of trolley
	// Trolley motors are connected as follows:
	// Left motor: P1^3(+) & P1^2(-)
	// Right motor: P1^1(-) & P1^0(+)


	if((d==0)&(c==0)&(b==0)&(a==0)) // no gesture, no manual action
	{
		CONTROL=0x00; // all actions stopped
	}

	if((d==1)&(c==0)&(b==0)&(a==1)) // Forward gesture
	{
		CONTROL=0x09; // move forward
	}

	if((d==0)&(c==1)&(b==1)&(a==0)) // Backward gesture
	{
		CONTROL=0x06; // move backward
	}

	if((d==1)&(c==0)&(b==0)&(a==0)) // Right gesture
	{
		CONTROL=0x08; // turn right
	}

	if((d==0)&(c==0)&(b==0)&(a==1)) // Left gesture
	{
		CONTROL=0x01; // turn left
	}

	} // while closed

	} // main closed