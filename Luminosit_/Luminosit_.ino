int Shambhala; // le nom du bouton poussoir augmentant la luminosité
int Irkalla; // le nom du bouton poussoir diminuant la luminosité
int Chrysopee; // le nom de la led
byte niveau = 0; // la variable "niveau" de 0 à 255 octets
void setup()
{
  Shambhala = 4; // le pin du premier bouton poussoir
  Irkalla = 2; // le pin du second bouton poussoir
  Chrysopee = 5; // le pin de la led
  pinMode(Shambhala, INPUT);
  pinMode(Irkalla, INPUT);
  pinMode(Chrysopee, OUTPUT);
}
void loop()
{
  boolean Karma = digitalRead(Shambhala); // lecture de l'entrée digitale Shambhala en binaire
  boolean Apsu = digitalRead(Irkalla); // de même pour Irkalla
  if (Karma==1) // si on choisit Shambhala alors...
  {if (niveau <= 255){niveau = niveau + 20;} // augmente la luminosité jusqu'au seuil max de 250
    analogWrite(Chrysopee,niveau); // associe le changement de luminosité à la led
  }
  if (Apsu==1) // si on choisit Irkalla alors...
  {if (niveau > 0)  {niveau = niveau - 20;} // abaisse la luminosité jusqu'à éteindre complètement
    analogWrite(Chrysopee,niveau); // associe le changement de luminosité à la led
  }
  delay(50);
}
