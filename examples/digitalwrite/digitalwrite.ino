#include <ShiftRegister.h>

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;
ShiftRegister shifter(latchPin, clockPin, dataPin);

void setup() {
  shifter.begin();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    shifter.digitalWrite(i, HIGH);
    delay(1000);
  }
  for (int i = 0; i < 8; i++) {
    shifter.digitalWrite(i, LOW);
    delay(1000);
  }
}
