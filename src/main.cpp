#include <Arduino.h>
#include "esp_camera.h"
#include <WiFi.h>
#include "credentials.h"

WiFiServer server(80);



void setup() {
Serial.begin(9600);
Serial.print("Verbinden mit...");
Serial.println(ssid);
WiFi.begin(ssid, password);

delay(2000);

Serial.println("Verbunden");
Serial.println("IP address:");
Serial.println(WiFi.localIP());
server.begin();
}

void loop() {

  WiFiClient client = server.available();  
  client.println("<!DOCTYPE html><html>");
  client.println("<head><title>Sensordaten</title></head>");
  client.println("<body><h1>DHT 11</h1><p>Temperatur</p><p>Luftfeuchtigkeit</p><p>Verwendet wurden ein DHT11 und ein Esp32<br>Ziel ist es die vom DHT11 gemessene Temperatur<br>auf einer Website anzuzeigen.<br></p></body>");
  client.println("</html>");

}