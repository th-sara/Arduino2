#include <Arduino.h>

int LED = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0 ; i < 256 ; i += 5){
    analogWrite(LED,i); // We use this function to write on Analog Pins.
    delay(100); //This function is used to let us see the difference better.
  }
}


