
/*
	8051 REMOTE CONTROLLING WITH EDGE AVOIDING ROBOT

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

/*
sbit d=P0^3; // 'd' output of receiver connected to P0^3
sbit c=P0^2; // 'c' output of receiver connected to P0^2
sbit b=P0^1; // 'b' output of receiver connected to P0^1
sbit a=P0^0; // 'a' output of receiver connected to P0^0

sbit LS=P0^7; // left IR sensor connected to P0^7
sbit RS=P0^5; // right IR sensor connected to P0^5

*/

#include <reg52.h>
#include "delay.c"
#define Motors P1 
#define Buzzer P3

sbit d=P0^3;
sbit c=P0^2;
sbit b=P0^1;
sbit a=P0^0;

sbit LS=P0^7;
sbit RS=P0^5;

	int main()
	{
	P1=0x00;  // this will keep all outputs of PORT1 to 0000 0000 initially
	delay(1); // momentary delay

	while(1) // infinite loop
	{
	delay(10); 	 // perceptible pause to allow 
				 // starting up the receiver module

	if((d==1)&(c==1)&(b==1)&(a==1)&(LS==1)&(RS==1)) // transmitter is inactive 1111 
				 									// and IR sensors are out of table edge 1010
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x0A; // power right turn
		delay(600);
		Motors=0x00;
	}

	if((d==0)&(c==1)&(b==1)&(a==0)&(LS==1)&(RS==1)) // transmitting FORWARD action 1001 
				 									// and IR sensors are out of table edge
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x0A; // power right turn
		delay(600);
		Motors=0x00;
	}

	if((d==0)&(c==1)&(b==1)&(a==0)&(LS==0)&(RS==1)) // transmitting FORWARD action 1001 
				 									// and IR sensors are out of table edge
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x05; // power left turn
		delay(600);
		Motors=0x00;
	}

	if((LS==0)&(RS==1)) // right IR sensor is out of table edge
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x05; // power left turn
		delay(600);
		Motors=0x00;
	}

	if((d==0)&(c==1)&(b==1)&(a==0)&(LS==1)&(RS==0)) // transmitting FORWARD action 1001 
				 									// and IR sensors are out of table edge
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x0A; // power right turn
		delay(600);
		Motors=0x00;
	}

	if((LS==1)&(RS==0)) // left IR sensor is out of table edge
	{
		Motors=0x00; // stop
		Buzzer=0x01; // buzzer sounds
		delay(500);
		Buzzer=0x00; // buzzer stops
		Motors=0x06; // backward 
		delay(500); 		
		Motors=0x0A; // power right turn
		delay(600);
		Motors=0x00;
	}

	if((d==1)&(c==1)&(b==1)&(a==1)&(LS==0)&(RS==0)) // transmitter INACTIVE and IR sensors on white
	{
		Motors=0x00; // stop
		delay(2);
	}

	if((d==0)&(c==1)&(b==1)&(a==0)&(LS==0)&(RS==0)) // transmitting FORWARD action and IR sensors on white
	{
		Motors=0x09; // forward
		delay(2);
	}

	if((d==1)&(c==0)&(b==0)&(a==1)&(LS==0)&(RS==0)) // transmitting BACKWARD action and IR sensors on white
	{
		Motors=0x06; // backward
		delay(2);
	}

	if((d==0)&(c==1)&(b==0)&(a==1)&(LS==0)&(RS==0)) // transmitting POWER RIGHT TURN action and IR sensors on white
	{
		Motors=0x0A; // power right turn
		delay(2);
	}

	if((d==1)&(c==0)&(b==1)&(a==0)&(LS==0)&(RS==0)) // transmitting POWER LEFT TURN action and IR sensors on white
	{
		Motors=0x05; // power left turn
		delay(2);
	}

	if((d==0)&(c==1)&(b==1)&(a==1)&(LS==0)&(RS==0)) // transmitting SOFT RIGHT TURN action and IR sensors on white
	{
		Motors=0x08; // soft right turn
		delay(2);
	}

	if((d==1)&(c==1)&(b==1)&(a==0)&(LS==0)&(RS==0)) // transmitting SOFT LEFT TURN action and IR sensors on white
	{
		Motors=0x01; // soft left turn
		delay(2);
	}

	} // while closed

	} // main closed