/*
  SlowBlink
  Turns on an LED on for 5 seconds, then off for 5 seconds, repeatedly.
  Derived from the 'Blink' example in the Arduino suite.
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);               // wait for 5 seconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);               // wait for 5 seconds
}
