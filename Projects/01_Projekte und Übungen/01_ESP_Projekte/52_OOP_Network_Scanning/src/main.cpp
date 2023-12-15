#include <Arduino.h>
#include "WiFi.h"

#define LedWhitePin 12
#define LedBluePin 14
#define LedGreenPin 27

void setup()
{
  pinMode(LedGreenPin, OUTPUT);
  pinMode(LedBluePin, OUTPUT);
  pinMode(LedWhitePin, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
}

void loop()
{
  Serial.println("Scanning available networks....");
  digitalWrite(LedGreenPin, HIGH);
  digitalWrite(LedBluePin, LOW);
  int n = WiFi.scanNetworks();
  if (n!=0)
  {
    digitalWrite(LedGreenPin, LOW);
    digitalWrite(LedBluePin, HIGH);
    Serial.print(n); Serial.println(" network(s) found");
    for (int i=0; i<n; ++i){
      Serial.print("network "); Serial.print(i +1); Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" ("); Serial.print(WiFi.RSSI(i)); Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " open " : " ***");
      delay(50);
    }
  }
  else{
    Serial.println("no available networks found");
    digitalWrite(LedGreenPin, LOW);
    digitalWrite(LedBluePin, LOW);
  }
  Serial.println("\n-------------------------------------------------\n");
  delay(5000);
}