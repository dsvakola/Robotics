/*
  Arudino Edge Avoiding Robot Code

  Vidyasagar Academy, Akola
  www.vsagar.org 
  
*/

#define LS 2      // left sensor // left sensor input pin defined
#define RS 3      // right sensor // right sensor input pin defined

#define LMpos 4       // left motor output pin defined
#define LMneg 5       // left motor output pin defined
#define RMneg 6       // right motor output pin defined
#define RMpos 7       // right motor output pin defined

void setup()
{
  pinMode(LS, INPUT); // pin-2 is defined as input pin
  pinMode(RS, INPUT); // pin-3 is defined as input pin
  
  pinMode(LMpos, OUTPUT); // pin-4 is defined as output pin
  pinMode(LMneg, OUTPUT); // pin-5 is defined as output pin
  pinMode(RMneg, OUTPUT); // pin-6 is defined as output pin
  pinMode(RMpos, OUTPUT); // pin-7 is defined as output pin
}

void loop() // infinite loop
{
  if(digitalRead(LS) && digitalRead(RS)) // white surface below both sensors
  {
    // forward
    digitalWrite(LMpos, HIGH);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, HIGH);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS)) // black surface below LS and white surface below RS
  {
    // stop
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // backward
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, HIGH);
    digitalWrite(RMneg, HIGH);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // soft right turn
    digitalWrite(LMpos, HIGH);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, LOW);
    delay(600);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS))) // white surface below LS and black surface below RS
  {
    // stop
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // backward
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, HIGH);
    digitalWrite(RMneg, HIGH);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // soft left turn
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, HIGH);
    delay(600);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS))) // black surface below both sensors
  {
    // stop
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // backward
    digitalWrite(LMpos, LOW);
    digitalWrite(LMneg, HIGH);
    digitalWrite(RMneg, HIGH);
    digitalWrite(RMpos, LOW);
    delay(1000);

    // soft right turn
    digitalWrite(LMpos, HIGH);
    digitalWrite(LMneg, LOW);
    digitalWrite(RMneg, LOW);
    digitalWrite(RMpos, LOW);
    delay(600);
  }
}
