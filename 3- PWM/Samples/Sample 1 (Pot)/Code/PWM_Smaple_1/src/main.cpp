#include <Arduino.h>

#define LED_PIN 5
#define POTENTIOMETER_PIN A0

int value = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  value = analogRead(POTENTIOMETER_PIN) >> 2;
  
  // {
  // value = analogRead(POTENTIOMETER_PIN) / 4;
  // }

  // {
  // value = analogRead(POTENTIOMETER_PIN)
  // value >>= 2;
  // }
  
  analogWrite(LED_PIN, value);
}
