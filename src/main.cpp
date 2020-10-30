#include <Arduino.h>
#include "esp_camera.h"
#include <WiFi.h>
#include "credentials.h"

WiFiServer server(80);





void setup() {
Serial.begin(9500);
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
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();  
  client.println("<!DOCTYPE html><html>");
  client.println("<head><title>mau</title></head>");
  client.println("<body><h1>Hallo</h1><p>......</p><p>------</p></body>");
  client.println("</html>");
}