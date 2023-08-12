#include <Arduino.h>

#define RED_POT_PIN A0
#define GRN_POT_PIN A1
#define BLU_POT_PIN A2

#define RED_LED_PIN 9
#define GRN_LED_PIN 10
#define BLU_LED_PIN 11

void setup() {
  pinMode(RED_POT_PIN, INPUT);
  pinMode(GRN_POT_PIN, INPUT);
  pinMode(BLU_POT_PIN, INPUT);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GRN_LED_PIN, OUTPUT);
  pinMode(BLU_LED_PIN, OUTPUT);
}

void loop() {
  changeRgbLedColor(
    analogRead(RED_POT_PIN) >> 2,
    analogRead(GRN_POT_PIN) >> 2,
    analogRead(BLU_POT_PIN) >> 2
  );
}

void changeRgbLedColor(
  int redLightValue, 
  int grnLightValue, 
  int bluLightValue
  ) {
  analogWrite(RED_LED_PIN, redLightValue);
  analogWrite(GRN_LED_PIN, grnLightValue);
  analogWrite(BLU_LED_PIN, bluLightValue);
}
