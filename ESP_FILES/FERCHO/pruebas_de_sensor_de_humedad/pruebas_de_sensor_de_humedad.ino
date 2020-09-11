#include <DHT.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#define DHTPIN 2
DHT dht(DHTPIN,DHT22);



void setup() {
 Serial.begin(115200);
 dht.begin();
}

void loop() {
 float TEMPERATURA=dht.readTemperature();
  float HUMEDAD=dht.readHumidity();
  Serial.println("temperatura:");
  Serial.println(TEMPERATURA);
   Serial.println("HUMEDAD:");
    Serial.println(HUMEDAD);
  delay(500);

}
