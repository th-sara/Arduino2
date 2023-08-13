#include <Arduino.h>

#define ADC_PIN A0
#define PWM_PIN 9

void setup()
{
  pinMode(ADC_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
}

void loop()
{
  analogWrite(PWM_PIN, analogRead(ADC_PIN) >> 2);
  delay(10);
}
