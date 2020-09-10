

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#ifndef STASSID
#define STASSID "Familia AS"
#define STAPSK  "AEIJAH1020"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "apex.oracle.com";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
String JSONMessage= "{\"TEMPERATURE\":10}";
StaticJsonDocument<200> doc;


 const char fingerprint[] PROGMEM ="2c fd d0 ea ed 0c 1d 3f cf fb 58 10 b2 b6 4f ba 31 db 74 a5";
WiFiClientSecure client;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  
  Serial.print("connecting to ");
  Serial.println(host);

  Serial.printf("Using fingerprint '%s'\n", fingerprint);
  client.setFingerprint(fingerprint);

  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/pls/apex/david_aworkspace/sinte/TESTTABLES";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: Esp32GateWay\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('$');
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");

 httpsPost(url); 
  
}

void loop() {
}


void httpsPost(String url) {

    doc["TEMPERATURE"] = 130;
    doc["TEST_VARCHAR"] = "SendingFromESP";
    String requestBody;
    serializeJson(doc, requestBody);
  // String data= "{\"TEMPERATURE\":\"2\"}";  
   if (client.connect(host, 443)) {
   client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: Esp32GateWay\r\n" +
               "Connection: close\r\n" +
               "Content-Type: application/json\r\n"+
               "Content-Length: "+requestBody.length()+"\r\n\r\n"+ 
               requestBody
                                                        );
                                                        
  }
}
