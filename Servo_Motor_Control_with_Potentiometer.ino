/*
  Controlling Servo motor with a potentiometer
  Created by: Vidyasagar Academy, Akola; www.vsagar.org
  Date: 04.05.2018, Version: 1.0 (Arduino UNO)
*/

#include <Servo.h>

Servo Servo_motor;  // assiging a variable "Servo_motor" with Servo

int potpin = 0;  // connect middle terminal of potentiometer to analog pin A0

int value;       // a variable "value" used to store the potentiometer positional value

void setup() 
{
  Servo_motor.attach(8);  // connect orange pin of servo motor to pin-8 of Arduino UNO
}

void loop() 
{
  value = analogRead(potpin);            // reads the "value" of potentiometer positional value
  value = map(value, 0, 1023, 0, 180);     // maping the "value" with servo rotation from 0-180 degree
  Servo_motor.write(value);              // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

