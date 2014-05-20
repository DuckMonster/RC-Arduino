#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
	Serial.begin(9600);
	mySwitch.enableReceive(0);
}

int characterI = 0, messageLength = 0;
char []messageBuffer;

void loop() {
	if (mySwitch.available()) {
		int value = mySwitch.getReceivedValue();

		if (characterI <= 0) {
			messageBuffer[messageLength - characterI] = (char)value;
			Serial.print("Character ");
			Serial.print(messageLength - characterI);
			Serial.print(" is ");
			Serial.println((char)value);

			if (--characterRead <= 0) {
				messageBuffer[messageLength] = '/0';
				Serial.println(messageBuffer);
			}
		} else {
			messageBuffer = new char[value+1];
			messageLength = value;
			characterI = value;
			Serial.print("Receiving new message, length: ");
			Serial.println(value);
		}
	}
}