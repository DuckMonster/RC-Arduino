#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
	Serial.begin(9600);
	mySwitch.enableTransmit(12);
}

void loop() {
	char []text = "Hejsan";

	int stringSize = 6;
	mySwitch.send(stringSize, 24);

	for(int i=0; i<stringSize; i++) {
		mySwitch.send(text[i], 24);
	}

	delay(500);
}