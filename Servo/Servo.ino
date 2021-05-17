#include <Servo.h> 

Servo myservo;  // créer un objet appelé myservo à partir du moule Servo

int pos = 0;    // variable pour stocker la position courante du servo

void setup() 
{ 
  myservo.attach(9);  // attacher notre objet myservo au servomoteur branché sur la broche 9 
} 


void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  // aller de 0° à 179°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
  for(pos = 180; pos>=1; pos-=1)     /// aller de 180° à 1°
  {                                
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
}
