#include <Arduino.h>

int adc_val = 0;

void setup() {
  pinMode(A0, INPUT);     // Set A0 pin as input
  Serial.begin(9600);    // Initialize serial communication at 9600 baud
}

void loop() {
  adc_val = analogRead(A0);   // Read the ADC value from A0 pin
  Serial.println(adc_val, 2);    // Print the voltage with 2 decimal places
  delay(100);   // Optional delay to control the print rate
}