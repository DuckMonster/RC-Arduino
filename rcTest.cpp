#incluce <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
	Serial.begin(9600);
	mySwitch.enableTransmit(12);
	mySwitch.enableRecieve(10);
}

void loop() {
	mySwitch.send(1555, 24);
	delay(1000);
	mySwitch.send(1560, 24);
	delay(1000);

	if (mySwitch.available()) {
		int value = mySwitch.getRecieveValue();

		if (value == 0) {
			Serial.println("What is this?");
		} else {
			Serial.print("Recieved ");
			serial.println(value);
		}
	}
}