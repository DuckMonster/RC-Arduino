#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
	Serial.begin(9600);
	mySwitch.enableReceive(0);
}

int characterI, messageLength;
char []messageBuffer;

void loop() {
	if (mySwitch.available()) {
		int value = mySwitch.getReceivedValue();

		if (characterRead <= 0) {
			messageBuffer[messageLength - characterI] = (char)value;
			if (--characterRead <= 0) Serial.println(messageBuffer);
		} else {
			messageBuffer = new char[value];
			Serial.print("Receiving new message, length: ");
			Serial.println(value);
		}
	}
}