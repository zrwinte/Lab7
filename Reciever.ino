#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include "rgb_lcd.h"
#include <Wire.h>

rgb_lcd lcd;

SoftwareSerial mySerial(6,7); // RX, TX


void setup() {
Serial.begin(9600); 
mySerial.begin(9600);
lcd.begin(16, 2); 
lcd.print("Waiting...");
}

void loop() {
if (mySerial.available() > 0) { 
String receivedMessage = mySerial.readString();
lcd.clear();
lcd.print(receivedMessage); 
mySerial.println(receivedMessage); 
}
}
