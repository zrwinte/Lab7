#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(7,6);

String message = "";

void setup() {
Serial.begin(9600);

mySerial.begin(9600);

Serial.println("Enter a message in the Serial Monitor, then press Enter.");
}

void loop() {
if (Serial.available() > 0) {
message = Serial.readStringUntil('\n');

mySerial.print(message);

Serial.println("Sent to receiver: " + message);

delay(100);
}
}
