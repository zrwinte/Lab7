#include <SoftwareSerial.h>
#include <LiquidCrystal.h> // Include the LCD library
#include "rgb_lcd.h"
#include <Wire.h>

rgb_lcd lcd;

SoftwareSerial mySerial(6,7); // RX, TX


void setup() {
Serial.begin(9600); // Initialize hardware serial connection
mySerial.begin(9600); // Initialize SoftwareSerial connection
lcd.begin(16, 2); // Initialize LCD (assuming 16x2 display)
lcd.print("Waiting...");
}

void loop() {
if (mySerial.available() > 0) { // If information is ready to be read...
String receivedMessage = mySerial.readString();
lcd.clear();
lcd.print(receivedMessage); // Display on LCD
mySerial.println(receivedMessage); // Print to Serial Monitor for debugging
}
}
