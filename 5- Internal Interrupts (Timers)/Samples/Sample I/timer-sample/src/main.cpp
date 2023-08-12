#include <Arduino.h>

#define LED_PIN 13


bool volatile toggle = false;


ISR(TIMER1_COMPA_vect) {
  toggle = !toggle;
  digitalWrite(LED_PIN, toggle);
}


void setup() {
  pinMode(LED_PIN, OUTPUT);

  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 31250;


  // TCCR1B &= ~(1 << 2);
  TCCR1B |= (1 << WGM12) | (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);

  interrupts();
}

void loop() {}
