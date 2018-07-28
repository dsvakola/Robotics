/*
  Program of controlling servo with a potentiometer
  Created by: Vidyasagar Academy, Akola; www.vsagar.org
  Date: 04.06.2017, Version: 1.4
*/

#include <Servo.h>

Servo Servo_motor; // create servo object

int potpin = 0; // **A0** pin is assigned to the center terminal of pot
int val; // variable to record the changing value of pot voltage

  void setup()
    {
      Servo_motor.attach(9); // servo motor attached to pin-9
    }
    
void loop()
  {
    val = analogRead(potpin); // the pot voltage is being read
    val = map(val, 0, 1023, 0, 179); // mapping
    Servo_motor.write(val); // controlling servo as per the value of potpin
    delay(15); // perceptible pause
}
