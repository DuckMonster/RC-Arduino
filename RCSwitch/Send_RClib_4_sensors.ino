/*
  Example for different sending methods
  
  http://code.google.com/p/rc-switch/
  
*/

#include <RCSwitch.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <wstring.h>

RCSwitch mySwitch = RCSwitch();
int Sensor[4];

int sens_power[4] = {8,7,6,5};
String message;
char message_bin[25];

void setup() {

  Serial.begin(9600);
  for(int i;i<4;i++){
    pinMode(sens_power[i],OUTPUT);
   }
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(12);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}



void loop() {
  delay(600000);
  for(int i=0;i<4;i++){
    digitalWrite(sens_power[i], HIGH);
    delay(5000);
    Sensor[i]=analogRead(i);
    digitalWrite(sens_power[i], LOW);
  // Serial.print("debug, Sensor get: ");
  // Serial.println(Sensor[i]);
   } 
  
  /* Same switch as above, but using decimal code */
 for(int a=0; a<11;a++){ 
  for(int i=0;i<4;i++){
    message = String("BB_")+String(i)+String("_")+String(Sensor[i]);
    message.toCharArray(message_bin,25);
    //mySwitch.send(Sensor[i],32);
    Serial.println(message_bin);
    mySwitch.sendTriState(message_bin);
    Serial.print("sensor: ");
    Serial.print(i);
    Serial.print(", Värde: ");
    Serial.println(Sensor[i]);
    
    delay(300);
    }
    
  Serial.println("-------------------------");
  }
}

