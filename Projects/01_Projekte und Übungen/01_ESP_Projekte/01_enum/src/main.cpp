#include <Arduino.h>

bool statusspielen = false;
bool statusWarteAufInput = false;

enum status
{
	STATUS_NORMAL,
	STATUS_PAUSE,
	STATUS_FERTIG
} state;

void checkBTN();
long previousMillis = 0;

void setup()
{
	Serial.begin(115200);
	state = STATUS_PAUSE;
	Serial.print(state);
	checkBTN();
	
}

void loop()
{
	unsigned long currentMillis = millis();
	
	if (currentMillis - previousMillis >= 2000)
	{
	previousMillis = currentMillis;
	state = STATUS_FERTIG;
	}
	
	switch(state)
	{
		case STATUS_NORMAL:
			Serial.println("Es kann los gehen! ");
			break;
		case STATUS_PAUSE:
			Serial.println("Jetzt ist Pause! ");
			break;
		case STATUS_FERTIG:
			Serial.println ("Wir sind fertig! ");
			break;
	}
	
	delay(500);
	
	delay(50);
}
	
	void checkBTN()
	{
		state = STATUS_NORMAL;
	}