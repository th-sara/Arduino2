#include <Arduino.h>

#define LED_PIN 4
#define SWITCH_PIN 2

bool led_state = false;
bool last_state = false;
bool curr_state = false;

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  curr_state = digitalRead(SWITCH_PIN);

  if(curr_state && !last_state){
    led_state = !led_state;
    digitalWrite(LED_PIN, led_state);
  }

  last_state = curr_state;
}