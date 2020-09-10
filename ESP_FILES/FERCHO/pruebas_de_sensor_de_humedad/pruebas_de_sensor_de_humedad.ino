#include <DHT.h>
#include <DHT_U.h>

DHT dht(SENSOR,DHT22)



void setup() {
 Serial.begin(9600);
 dht.begin();
}

void loop() {
  TEMPERATURA=dht.readTemperature();
  HUMEDAD=dht.readHumidity();
  Serial.print("temperatura:");
  Serial.println(TEMPERATURA);
   Serial.println("HUMEDAD:");
    Serial.println(HUMEDAD);
  delay(500);
}
