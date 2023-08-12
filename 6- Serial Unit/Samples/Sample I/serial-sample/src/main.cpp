#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Listening...");
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println(Serial.readString());
  }
}
