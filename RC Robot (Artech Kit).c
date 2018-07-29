
/*
	8051 Remote Controlled Robot for new kit
	Created by: Vidyasagar Academy, Akola
	Website: http://vsagar.og/
	Date: 01.07.2017

	========= READ THE CONNECTION DETAILS CAREFULLY FIRST ==========

	// The output of receiver is connected to PORT0
	// i.e. to P0^3 to P0^0

	// The two motors are connected to PORT1 as follows:
	// Left motor: P1^3(+) & P1^2(-)
	// Right motor: P1^1(-) & P1^0(+)

	// when you press switches D & A robot will move forward
	// when you press switches C & B robot will move backward
	// and so on...

*/

#include <reg52.h>
#include "delay.c"
#define Motors P1 

sbit d=P0^3;
sbit c=P0^2;
sbit b=P0^1;
sbit a=P0^0;

	int main()
	{

	while(1) // infinite loop
	{
	delay(10); 	 // perceptible pause to allow 
				 // starting up the receiver module

	if((d==1)&(c==1)&(b==1)&(a==1)) // 0000	 all switches of transmitter are NOT PRESSED
	{
		Motors=0x00; // stop
		delay(5); 		
	}

	if((d==0)&(c==1)&(b==1)&(a==0)) // 1001	 Press switches D & A 
	{
		Motors=0x09; // forward
		delay(5); 		
	}

	if((d==1)&(c==0)&(b==0)&(a==1)) // 0110	 Press switches C & B
	{
		Motors=0x06; // backward
		delay(5); 		
	}

	if((d==0)&(c==1)&(b==1)&(a==1)) // 1000	 Press switches D only
	{
		Motors=0x08; // soft right turn
		delay(5); 		
	}

	if((d==0)&(c==1)&(b==0)&(a==1)) // 1010	 Press switches D & B
	{
		Motors=0x0A; // power right turn
		delay(5); 		
	}

	if((d==1)&(c==1)&(b==1)&(a==0)) // 0001	 Press switches A only
	{
		Motors=0x01; // soft left turn
		delay(5); 		
	}

	if((d==1)&(c==0)&(b==1)&(a==0)) // 0101	 Press switches C & A
	{
		Motors=0x05; // power left turn
		delay(5); 		
	}

	} // while closed

	} // main closed