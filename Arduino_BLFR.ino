/*
  Program of black line following robot
  Created by: Vidyasagar Academy, Akola; www.vsagar.org
  Date: 04.06.2017, Version: 1.0
*/

/* ==== IMPORTANT NOTE ====
 *  DO NOT CONNECT THE MOTORS DIRECTLY TO THE GIVEN PINS
 *  CONNECT THEM THROUGH MOTOR SHIELD LIKE L293D
 */

// First we define sensor inputs
#define LS 2 // output terminal of left sensor connected to pin-2 
#define RS 3 // output terminal of right sensor connected to pin-3

// Now we define motor connections
#define LMpos 4 // left motor (+)
#define LMneg 5 // left motor (-)
#define RMpos 6 // right motor (+)
#define RMneg 7 // right motor (-)

  void setup()
  {
    pinMode(LS, INPUT);
    pinMode(RS, INPUT);
    pinMode(LMpos, OUTPUT);
    pinMode(LMneg, OUTPUT);
    pinMode(RMpos, OUTPUT);
    pinMode(RMneg, OUTPUT);
  }
  
  void loop()
  {
    if(digitalRead(LS) && digitalRead(RS)) // Stop
    {
      digitalWrite(LMpos, LOW);
      digitalWrite(LMneg, LOW);
      digitalWrite(RMpos, LOW);
      digitalWrite(RMneg, LOW);
    }
  
    if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right
    {
      digitalWrite(LMpos, LOW);
      digitalWrite(LMneg, LOW);
      digitalWrite(RMpos, HIGH);
      digitalWrite(RMneg, LOW);
    }
    
    if(digitalRead(LS) && !(digitalRead(RS))) // turn left
    {
      digitalWrite(LMpos, HIGH);
      digitalWrite(LMneg, LOW);
      digitalWrite(RMpos, LOW);
      digitalWrite(RMneg, LOW);
    }
    
    if(!(digitalRead(LS)) && !(digitalRead(RS))) // Forward
    {
      digitalWrite(LMpos, HIGH);
      digitalWrite(LMneg, LOW);
      digitalWrite(RMpos, HIGH);
      digitalWrite(RMneg, LOW);
    }
    } // void loop closed
