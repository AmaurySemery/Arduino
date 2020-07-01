// Code pour utiliser les capteurs d'humidité et de température

#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float tmin = 999;
float tmax = -999;
int hmin = 999;
int hmax = -999;

int eeAddress = 0;


void setup () {
dht.begin();
Serial.begin(115200);
Serial.println("Hello!");
}

void update_stats(float tmp, int hum) {
tmin = min(tmin, tmp);
tmax = max(tmax, tmp);
hmin = min(hmin, hum);
hmax = max(hmax, hum);
}

void loop () {

// If any message is available on serial port :
if (Serial.available() > 0) {

String message = Serial.readStringUntil('\n');
message.toUpperCase();

Serial.print("DEBUG: ");
Serial.println(message);

float tmp = dht.readTemperature();
int hum = dht.readHumidity();
update_stats(tmp, hum);

if (message == "HUM" || message == "STH" || message == "ALL") {
Serial.print("HINS:");
Serial.println(hum);
}
if (message == "TMP" || message == "STT" || message == "ALL") {
Serial.print("TINS:");
Serial.println(tmp);
}
if (message == "STT" || message == "ALL") {
Serial.print("TMIN:");
Serial.println(tmin);
Serial.print("TMAX:");
Serial.println(tmax);
}
if (message == "STH" || message == "ALL") {
Serial.print("HMIN:");
Serial.println(hmin);
Serial.print("HMAX:");
Serial.println(hmax);
}
}
delay(50);
}
