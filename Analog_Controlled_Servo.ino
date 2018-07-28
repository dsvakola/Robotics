
/*
  Program of controlling servo motor using analog input
  Created by: Vidyasagar Academy, Akola; www.vsagar.org
  Date: 04.06.2017, Version: 1.3
*/

/*
  ======= Important Note =======
  To observe what is happening in this program, we suggest you to connect one LED 
  across pin-9 and ground through a small resistor of 330 ohms.
  You will see that the LED becomes brighter slowly and then fades away slowly. 
*/

int Servo_motor = 9; // assigning servo pin-9 

void setup()
  {
    pinMode(Servo_motor, OUTPUT);
  }

void loop()
  {
    for(int a=0; a<255; a++)
    {
      analogWrite(Servo_motor, a);
      delay(10);
    }
    
    for(int a=255; a>0; a--)
    {
      analogWrite(Servo_motor, a);
      delay(10);
    }
  }

