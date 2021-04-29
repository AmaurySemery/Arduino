// Je déclare l'entrée analogique où j'ai branché ma photorésistance
const int analogInPin = A2;
// Je déclare la sortie analogique où j'ai branché mon buzzer
const int analogOutPin = 8;

// La valeur de base de ma photorésistance est de 0
int photoValeur = 0;
// La valeur de base de mon buzzer est de 0
int buzzerValeur = 0;

// Le programme de démarrage
void setup() {
// Je démarre la communication avec le moniteur série à 9600 bauds  
  Serial.begin(9600);
}

// Le programme qui va tourner en boucle après le démarrage
void loop() {
  // Sur Tinkercad, la valeur de la photorésistance varie entre 6 et 679
  photoValeur = analogRead(analogInPin);
  // 6/679 correspond à la fourchette de valeurs pour la photorésistance sur Tinkercad
  // 50/30000 correspnd aux Hz pour faire varier le son du buzzer
  // On traduit donc la valeur de la photo en Hz puis on la stocke
  buzzerValeur = map(photoValeur, 6, 679, 50, 30000);
  // tone permet de lire la valeur stockée par buzzerValeur sur la broche 8 (du buzzer donc)
  tone(8,buzzerValeur);
  
  // On affiche sur le moniteur série la valeur de la photorésistance
  Serial.print("Photoresistance = ");
  Serial.print(photoValeur);
  // On affiche sur le moniteur série la valeur du buzzer
  Serial.print("\t Buzzer = ");
  Serial.println(buzzerValeur);

  // Le programme se relance toutes les 2 millisecondes
  delay(2);
}
