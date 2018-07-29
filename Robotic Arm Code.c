
/*
	8051 Remote Controlled Robotic Arm
	Created by: Vidyasagar Academy, Akola
	Website: http://vsagar.og/
	Date: 25.05.2014
*/

#include <reg51.h>
#include "delay.c"

#define TAG P1 // The trolley motors, Arm motor and Gripper motor connected to PORT1

sbit d=P0^3;
sbit c=P0^2;
sbit b=P0^1;
sbit a=P0^0; // receiver's output signals connected to P0^3-P0^0

	int main()
	{

	// nothing to write here

	while(1) // infinite loop
	{
	delay(10); 	 // perceptible pause to allow 
				 // starting up the receiver module

	// Controlling signals for movement of robotic arm and gripper
	// Arm motor: P1^7(+) & P1^6(-)
	// Gripper motor: P1^5(+) & P1^4(-)

	if((d==0)&(c==1)&(b==1)&(a==1)) // 1000	 only switch 'D' is pressed
	{
		TAG=0x80; // i.e. 0b1000 0000 means arm moves down
		delay(5); 		
	}

	if((d==1)&(c==1)&(b==1)&(a==0)) // 0001	 only switch 'A' is pressed
	{
		TAG=0x40; // i.e. 0b0100 0000 means arm moves up
		delay(5); 		
	}

	if((d==1)&(c==0)&(b==1)&(a==1)) // 0100	 only switch 'C' is pressed
	{
		TAG=0x20; // i.e. 0b0010 0000 means gripper opens
		delay(5); 		
	}

	if((d==1)&(c==1)&(b==0)&(a==1)) // 0010	 only switch 'B' is pressed
	{
		TAG=0x10; // i.e. 0b0001 0000 means gripper closes
		delay(5); 		
	}

	// Controlling signals for movement of trolley
	// Trolley motors are connected as follows:
	// Left motor: P1^3(+) & P1^2(-)
	// Right motor: P1^1(-) & P1^0(+)


	if((d==1)&(c==1)&(b==1)&(a==1)) // 0000	 all switches of transmitter are not pressed
	{
		TAG=0x00; // all motions of trolley, arm and gripper are stopped
		delay(5); 		
	}

	if((d==0)&(c==1)&(b==1)&(a==0)) // 1001	 switch 'D' & 'A' are pressed
	{
		TAG=0x09; // trolley moves forward
		delay(5); 		
	}

	if((d==1)&(c==0)&(b==0)&(a==1)) // 0110	 switch 'C' & 'B' are pressed
	{
		TAG=0x06; // trolley moves backward
		delay(5); 		
	}

	if((d==0)&(c==1)&(b==0)&(a==1)) // 1010	 switch 'D' & 'B' are pressed
	{
		TAG=0x08; // soft right turn
		delay(5); 		
	}

	if((d==1)&(c==0)&(b==1)&(a==0)) // 0101	 switch 'C' & 'A' are pressed
	{
		TAG=0x01; // soft left turn
		delay(5); 		
	}


	} // while closed

	} // main closed