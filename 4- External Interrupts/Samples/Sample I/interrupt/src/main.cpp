#include <Arduino.h>

#define BUT_PIN 3
#define LED_PIN 4

volatile bool LEDState = false;
volatile bool changed = false;

void setup() {
  pinMode(BUT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  attachInterrupt(
    digitalPinToInterrupt(BUT_PIN),
    toggleLED,
    RISING
  );
}

void loop() {
  if(changed) {
    digitalWrite(LED_PIN, LEDState);
    changed = false;
  }
}


void toggleLED() {
  LEDState = !LEDState;
  changed = true;
}