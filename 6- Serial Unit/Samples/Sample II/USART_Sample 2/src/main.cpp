#include <Arduino.h>

/*
There are some problems with this code!
Let's run the code and find them out.

Attention: As you can see, there are two Serial classes which are being used.
Therefore this code is written for an Arduino board with more than one serial
unit (not the Uno model for sure), which is Arduino Mega in this case.
*/

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  String str1 = Serial1.readString();
  String str0 = Serial.readString();
  if (str1 != "" && str1 != "\n") {
    Serial.println(str1);
    delay(100);
  }

  if (str0 != "" && str0 != "\n") {
    Serial1.println(str0);
    delay(100);
  }
}
