#include <Arduino.h>

#define LED_PIN 3
#define DELAY_PERIOD 20

int adc_val = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    analogWrite(LED_PIN, i);
    delay(DELAY_PERIOD);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(LED_PIN, i);
    delay(DELAY_PERIOD);
  }

  delay(DELAY_PERIOD);
}
