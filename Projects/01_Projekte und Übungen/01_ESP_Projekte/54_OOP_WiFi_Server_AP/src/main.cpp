#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>


#define ssid "ESP32_AP"
#define password "12345678"
#define LedWhitePin 12
#define LedBluePin 14
#define LedGreenPin 27

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
WebServer server(80);

bool LEDStatus = LOW;

void handle_OnConnect();
void handle_ledON();
void handle_ledOFF();
void handle_NotFound();

void setup() {
  Serial.begin(115200);
  pinMode(LedWhitePin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledON);
  server.on("/ledoff", handle_ledOFF);
  server.onNotFound(handle_NotFound);  
  server.begin();
  Serial.println("HTTP Server Started");
}

void loop() {
  server.handleClient();
  if(LEDStatus){
    digitalWrite(LedWhitePin, HIGH);
  }
  else{
    digitalWrite(LedWhitePin, LOW);
  }
}

String getHTML(){
  String htmlcode = "<!DOCTYPE html> <html>\n";
  htmlcode +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  htmlcode +="<title>LED Control</title>\n";

  htmlcode +="</head>\n";
  htmlcode +="<body>\n";
  htmlcode +="</h1>ESP32 Web Server</h1>\n";
  htmlcode +="</h3>A simple demo using Access Point(AP) Mode</h3>\n";
  if(LEDStatus){
    htmlcode +="<p>Blue LED Status: ON</p><a href=\"/ledoff\">Turn it OFF</a>\n";
  }
  else{
    htmlcode +="<p>Blue LED Status: OFF</p><a href=\"/ledon\">Turn it ON</a>\n";
  }
  htmlcode +="</body>\n";
  htmlcode +="</html>\n";

  return htmlcode;
}

void handle_OnConnect(){
  LEDStatus = LOW;
  Serial.println("LED Status: OFF");
  server.send(200, "text/html",getHTML());
}

void handle_ledON(){
  LEDStatus = HIGH;
  Serial.println("LED Status: ON");
  server.send(200, "text/html",getHTML());
}

void handle_ledOFF(){
  LEDStatus = LOW;
  Serial.println("LED Status: OFF");
  server.send(200, "text/html",getHTML());
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not Found");
}