#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "WLAN_HOME"
#define WIFI_PASSWORD "XRRIYXMDQAQJZFNJ"

WiFiMulti wifiMulti;

void setup()
{
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("starting");
}

bool isConnected = false;

void loop(){
  if(WiFi.status() == WL_CONNECTED && !isConnected){
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
    isConnected = false;
  }
}