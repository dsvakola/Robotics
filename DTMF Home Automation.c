
/*
	8051 DTMF Home Automation System
	Created by: Prof. Dattaraj Vidyasagar 
	for Vidyasagar Academy, Akola
	Website: http://vsagar.og/
	
	Date: 26.04.2017
*/

#include <reg51.h>
#include "delay.c"

#define Devices P1 // 4 different devices connected to PORT1
#define DTMF P0 // 4 pins (P0^3 to P0^0) of PORT0 will receive signal form DTMF sensor 

				// connect outputs of DTMF sensor to PORT0 as follows:
				// D3--P0^3,  D2--P0^2,  D1--P0^1  and  D0--P0^0 

	int main()
	{

	P1=0x00;  // this will keep all outputs of PORT1 to 0000 0000 initially
	delay(1); // momentary delay

	P0=0x00; //  defining all pins of PORT0 as input pins

	while(1) // infinite loop
	{
	delay(10); 	 // perceptible pause to allow 
				 // starting up the transmitter/receiver modules and dev. board

	// Controlling signals for the 8 devices connected to PORT1 i.e. from P1.0 to P1.7
	// you can use any number of devices from 1 to 8

	if(DTMF==0x0A) // '0' is pressed on calling mobile
	{
		Devices=0x00; // output of all pins of PORT1 is 0000 0000
		delay(2); 		
	}

	if(DTMF==0x01) // '1' is pressed on calling mobile
	{
		Devices=0x01; // only the device connected to P1^0 will be ON i.e. P1 = 0b 0000 0001
		delay(2); 		
	}

	if(DTMF==0x02) // '2' is pressed on calling mobile
	{
		Devices=0x02; // only the device connected to P1^1 will be ON i.e. P1 = 0b 0000 0010
		delay(2); 		
	}

	if(DTMF==0x03) // '3' is pressed on calling mobile
	{
		Devices=0x04; // only the device connected to P1^2 will be ON i.e. P1 = 0b 0000 0100
		delay(2); 		
	}

	if(DTMF==0x04) // '4' is pressed on calling mobile
	{
		Devices=0x08; // only the device connected to P1^3 will be ON i.e. P1 = 0b 0000 1000
		delay(2); 		
	}

	if(DTMF==0x05) // '5' is pressed on calling mobile
	{
		Devices=0x10; // only the device connected to P1^4 will be ON i.e. P1 = 0b 0001 0000
		delay(2); 		
	}

	if(DTMF==0x06) // '6' is pressed on calling mobile
	{
		Devices=0x20; // only the device connected to P1^5 will be ON i.e. P1 = 0b 0010 0000
		delay(2); 		
	}
			
	if(DTMF==0x07) // '7' is pressed on calling mobile
	{
		Devices=0x40; // only the device connected to P1^6 will be ON i.e. P1 = 0b 010 0000
		delay(2); 		
	}

	if(DTMF==0x08) // '8' is pressed on calling mobile
	{
		Devices=0x80; // only the device connected to P1^7 will be ON i.e. P1 = 0b 1000 0000
		delay(2); 		
	}


	} // while closed

	} // main closed