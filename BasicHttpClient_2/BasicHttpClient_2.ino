#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial

WiFiMulti wifiMulti;

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

void setup() {


  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  USE_SERIAL.begin(115200);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  wifiMulti.addAP("POP_SENSORS", "P0PS3NS0RS!");

}

void loop() {
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y à en dessous

    HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP

    float t = random(25, 35); // t = nombre au hasard entre 25 & 35
    USE_SERIAL.println("[DEBG] " + String(t));

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
    http.begin("http://192.168.1.200:1883/T/" + String(t)); //HTTP => démarre connexion vers le serveur mentionné

    USE_SERIAL.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET(); // soumet une requête de type "get", puis récupère résultat qui sera collée dans HTTP

    // httpCode will be negative on error
    if (httpCode > 0) { // si c'est supérieur à 0, il refait un test)
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) { // Si ça s'est bien passé, il refait une variable où il met le getString puis affiche à l'écran => on a reçu un code 200
        String payload = http.getString();
        USE_SERIAL.println(payload);
        if (payload == "ON") {
          digitalWrite(4, HIGH);
        }
        if (payload == "OFF") {
          digitalWrite(4, LOW);
        }
      }
    } else { // sinon, il dit que ça ne fonctionne pas
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

  delay(5000); // le tout est fait toutes les 5 secondes.
}
