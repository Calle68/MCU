#include <Arduino.h>
#include "WiFi.h"

#define LedWhitePin 12
#define LedBluePin 14
#define LedGreenPin 27

const char *ssid = "WLAN_HOME";
const char *password = "XRRIYXMDQAQJZFNJ";

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(LedWhitePin, OUTPUT);
  pinMode(LedBluePin, OUTPUT);
  pinMode(LedGreenPin, OUTPUT);
  delay(10);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LedBluePin, !digitalRead(LedBluePin));
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP adresse: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LedBluePin, LOW);
  digitalWrite(LedGreenPin, HIGH);
  server.begin();
}

int value = 0;

void loop()
{
  WiFiClient client = server.available(); // listen for incomming clients

  if (client)
  {                                // if you get client,
    Serial.println("New Client."); // print a massage out the serial port
    String currentLine = "";       // make a String to holt incomming data from the client
    while (client.connected())
    { // loop while the client's conneted
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        if (c == '\n')
        { // if the byte is a newline character

          // if the current line is blank, you got two newline charracters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start white a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's comming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the White LED on pin 12 on. <br>");
            client.print("Click <a href=\"/L\">here</a> to turn the White LED on pin 12 off. <br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else
          { // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else bu a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")){
          digitalWrite(LedWhitePin, HIGH);
        }
        if (currentLine.endsWith("GET /L")){
          digitalWrite(LedWhitePin, LOW);
        }
      }
    }
    //close the connetion:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}