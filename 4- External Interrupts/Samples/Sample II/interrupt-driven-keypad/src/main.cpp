/*
  Let's say there are a few number of buttons (4 in this code), and we want
  to get informed when any of those is pushed. For this purpose, we connect 
  one end of each push button to VCC and the other end to an input pin of 
  the Arduino (with pull-down resistor, ofc). I used a keypad instead of 
  a bunch of push buttons as we all know what a keypad really is.

  But what if we don't want our microcontroller to keep checking for a change 
  in our input pins, without being able to do anything else? The answer is 
  obviously using an external interrupt. So here we are:

  A bunch of push buttons (i.e. a keypad) driven by interrupt.
*/


#include <Arduino.h>


const int INT_PIN = 3;
const int BUTTON_PINS[] = {7, 6, 5, 4};
const int NUMBER_OF_BUTTONS = sizeof(BUTTON_PINS) / sizeof(*BUTTON_PINS);


volatile bool isKeyPressed = false;

void keyPressed() {
  isKeyPressed = true;
}

void setup() {
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT);
  }
  pinMode(INT_PIN, INPUT);

  Serial.begin(9600);

  // INT_PIN becomes HIGH whenever any of those buttons are pushed. How?
  attachInterrupt(digitalPinToInterrupt(INT_PIN), keyPressed, RISING);
}

void loop() {
  if (isKeyPressed) {
    for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
      if (digitalRead(BUTTON_PINS[i]) == HIGH) {
        Serial.println("Button number " + String(i + 1) + " is pressed.");
        break;
      }
    }
    isKeyPressed = false;
  }
}
