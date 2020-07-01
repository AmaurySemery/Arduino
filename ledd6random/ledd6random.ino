// Allumage des LEDS suivant le résultat d'un D6.

int Botch = 2;
int Disappointed = 4;
int Meh = 6;
int Notbad = 8;
int Great = 10;
int Critality = 12;

void setup()
{  
   
  pinMode(Botch, OUTPUT);
  pinMode(Disappointed, OUTPUT);
  pinMode(Meh, OUTPUT);
  pinMode(Notbad, OUTPUT);
  pinMode(Great, OUTPUT);
  pinMode(Critality, OUTPUT);
  Serial.begin(9600);
  Serial.println("Tous autour du ring 3, 2, 1 ...");

  
}

void loop()
{
  int dice;
  dice = random(1,7);
  Serial.println("Combattez !");
  Serial.println(dice);
  digitalWrite(Botch, LOW);
  digitalWrite(Disappointed, LOW);
  digitalWrite(Meh, LOW);
  digitalWrite(Notbad, LOW);
  digitalWrite(Great, LOW);
  digitalWrite(Critality, LOW);

  
  if (dice == 1);{
  digitalWrite(Botch, HIGH);}
  if (dice == 2);{
  digitalWrite(Botch, HIGH);
  digitalWrite(Disappointed, HIGH);}
  if (dice == 3);{
  digitalWrite(Botch, HIGH);
  digitalWrite(Disappointed, HIGH);
  digitalWrite(Meh, HIGH);}
  if (dice == 4);{
  digitalWrite(Botch, HIGH);
  digitalWrite(Disappointed, HIGH);
  digitalWrite(Meh, HIGH);
  digitalWrite(Notbad, HIGH);}
  if (dice == 5);{
  digitalWrite(Botch, HIGH);
  digitalWrite(Disappointed, HIGH);
  digitalWrite(Meh, HIGH);
  digitalWrite(Notbad, HIGH);
  digitalWrite(Great, HIGH);}  
  if (dice == 6);{
  digitalWrite(Botch, HIGH);
  digitalWrite(Disappointed, HIGH);
  digitalWrite(Meh, HIGH);
  digitalWrite(Notbad, HIGH);
  digitalWrite(Great, HIGH);
  digitalWrite(Critality, HIGH);}
 delay(5000);
}
