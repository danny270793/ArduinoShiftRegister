#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int newLatch, int newClock, int newData) {
  this -> ShiftRegister_LatchPin = newLatch;
  this -> ShiftRegister_ClockPin = newClock;
  this -> ShiftRegister_DataPin = newData;
}
void ShiftRegister::begin() {
  pinMode(this -> ShiftRegister_LatchPin, OUTPUT);
  pinMode(this -> ShiftRegister_ClockPin, OUTPUT);
  pinMode(this -> ShiftRegister_DataPin, OUTPUT);
}
void ShiftRegister::digitalWrite(int pin, int state) {
  if (state == HIGH || state == LOW) {
    this -> ShiftRegister_Pins[pin] = state;
    this -> ShiftRegister_Data = 0;
    for (int ShiftRegister_i = 0; ShiftRegister_i < 8; ShiftRegister_i++) {
      this -> ShiftRegister_Data += this -> ShiftRegister_Pins[ShiftRegister_i] * round(pow(2, ShiftRegister_i));
    }
    shiftData(this -> ShiftRegister_Data);
  }
}
void ShiftRegister::shiftData(int data) {
  if (data >= 0 and data <= 256) {
    digitalWrite(this -> ShiftRegister_LatchPin, LOW);
    shiftOut(this -> ShiftRegister_DataPin, this -> ShiftRegister_ClockPin, MSBFIRST, data);
    digitalWrite(this -> ShiftRegister_LatchPin, HIGH);
  }
}
void ShiftRegister::clean() {
  for (int ShiftRegister_i = 0; ShiftRegister_i < 8; ShiftRegister_i++) {
    this -> ShiftRegister_Pins[ShiftRegister_i] = LOW;
  }
  shiftData(0);
}