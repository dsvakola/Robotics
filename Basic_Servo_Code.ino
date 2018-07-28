/*
  Basic Servo motor code
  Created by: Vidyasagar Academy, Akola; www.vsagar.org
  Date: 04.05.2018, Version: 1.0 (Arduino UNO)
*/

#include <Servo.h> // including the servo motor header file

Servo Servo_motor; // assigning a variable "Servo_motor" to Servo

void setup() 
  { 
   Servo_motor.attach(8); // connect the orange pin to pin-8 of Ardunio UNO board
  }

void loop()
  {  
   Servo_motor.write(0); // restore the position of servo to starting point
   delay(2000);  
   Servo_motor.write(180); // turn the servo through 180 degree
   delay(2000);  
  }
