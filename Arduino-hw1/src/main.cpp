#include <Arduino.h>

int adc_val = 0;

bool led1_state = false;
bool led2_state = false;
bool led3_state = false;
bool led4_state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  adc_val = analogRead(A0);
  int val = map(adc_val, 0, 1023, 0, 100);
  if (val>= 0 && val< 25){
    led1_state = false;
    led2_state = false;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 25 && val< 50){
    led1_state = true;
    led2_state = false;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 50 && val< 75){
    led1_state = true;
    led2_state = true;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 75 && val< 90){
    led1_state = true;
    led2_state = true;
    led3_state = true;
    led4_state = false;
  }
  else if(val>= 90){
    led1_state = true;
    led2_state = true;
    led3_state = true;
    led4_state = true;
  }
  digitalWrite(A1, led1_state);
  digitalWrite(A2, led2_state);
  digitalWrite(A3, led3_state);
  digitalWrite(A4, led4_state);
}