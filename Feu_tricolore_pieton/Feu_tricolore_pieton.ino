// On déclare le bouton et son état
const int bouton = 2;
int boutonEtat = 0;

// On déclare les leds du feu
const int feuVert = 10;
const int feuOrange = 11;
const int feuRouge = 12;

// On déclare les leds pour les piétons
const int pietonVert = 8;
const int pietonRouge = 9;

// Programme qui se lance une fois au démarrage
void setup()
{
// On déclare les leds du feu tricolore comme des sorties
pinMode(feuVert, OUTPUT);
pinMode(feuOrange, OUTPUT);
pinMode(feuRouge, OUTPUT);

// De même pour les leds pour les piétons
pinMode(pietonVert, OUTPUT);
pinMode(pietonRouge, OUTPUT);

// On déclare le bouton comme une entrée
pinMode(bouton, INPUT);
}

// Programme qui se lance en boucle après le démarrage
void loop()
{
// On lit l'état du bouton (HIGH ou LOW)
boutonEtat = digitalRead(bouton);

// Si on presse le bouton au moment où le feu est vert...
if (boutonEtat == HIGH && feuVert == HIGH){
// Le programme suivant est lancé
digitalWrite(feuVert, LOW);
digitalWrite(feuOrange, HIGH);
delay(1000);
digitalWrite(feuOrange, LOW);
digitalWrite(feuRouge, HIGH);
digitalWrite(pietonVert, HIGH);
digitalWrite(pietonRouge, LOW);
delay(5000);
digitalWrite(pietonVert, LOW);
digitalWrite(pietonRouge, HIGH);
}
// Si on presse le bouton à un autre moment...
if (boutonEtat == HIGH) {
// Le programme suivant est lancé
digitalWrite(feuVert, LOW);
digitalWrite(feuOrange, LOW);
digitalWrite(feuRouge, HIGH);
digitalWrite(pietonVert, HIGH);
digitalWrite(pietonRouge, LOW);
delay(5000);
digitalWrite(pietonVert, LOW);
digitalWrite(pietonRouge, HIGH);
}
// Si on ne presse pas le bouton...
else {
// C'est cet état de base qui s'impose
digitalWrite(pietonRouge, HIGH);
digitalWrite(pietonVert, LOW);
}
// Sans considérer le bouton, ci-dessous la routine de programme des feux tricolores
digitalWrite(feuRouge, LOW);
digitalWrite(feuVert, HIGH);
delay(3000);
digitalWrite(feuVert, LOW);
digitalWrite(feuOrange, HIGH);
delay(1000);
digitalWrite(feuOrange, LOW);
digitalWrite(feuRouge, HIGH);
delay(3000);
digitalWrite(feuRouge, LOW);

}
