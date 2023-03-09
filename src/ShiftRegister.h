#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister {
  public: ShiftRegister(int newLatch, int newClock, int newData);
  void begin();
  void digitalWrite(int pin, int state);
  void shiftData(int data);
  void clean();
  private: int ShiftRegister_Pins[8];
  int ShiftRegister_Data;
  int ShiftRegister_LatchPin,
  ShiftRegister_ClockPin,
  ShiftRegister_DataPin;
};
#endif
