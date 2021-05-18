// int contient une variable qui est un nombre entier
int switchState = 0;

// Le setup est exécuté une seule fois
void setup(){
// Configuration des broches connectées aux LED en sorties
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
// Configuration de la broche connectée à l'interrupteur en entrée
  pinMode(2,INPUT);
}

// Le loop est une boucle qui se répète continuellement après lancement du setup
void loop(){
// digitalRead vérifie le niveau de la tension sur la broche désignée
// S'il y a une tension, la variable renverra HIGH
// S'il n'y en a pas, la variable renverra LOW
  switchState = digitalRead(2);

// if détermine si la comparaison est vraie ou fausse
// ici, on vérifie l'état de l'interrupteur
if (switchState == LOW) {
// pas d'appui sur le bouton
digitalWrite(3,HIGH); // LED verte allumée
digitalWrite(4,LOW); // LED rouge n°1 éteinte
digitalWrite(5,LOW); // LED rouge n°2 éteinte
}
else {
// appui sur le bouton
digitalWrite(3,LOW); // LED verte éteinte
digitalWrite(4,LOW); // LED rouge n°1 éteinte
digitalWrite(5,HIGH); // LED rouge n°2 allumée
delay(250); // pause de 250ms avant la suite
//faire clignoter les LED
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
delay(250); // pareil
}
}
// Retour au début de la boucle loop
