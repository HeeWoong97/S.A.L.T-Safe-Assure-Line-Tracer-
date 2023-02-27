#ifndef _INFRARED_H_
#define _INFRARED_H_

#include <Arduino.h>
#include "Motor.h"

#define LEFT_SENSOR_PIN   A0
#define RIGHT_SENSOR_PIN  A5

#define INFRARED_PIN      A3

#define INTERVAL        3000

extern bool is_somthing;

class Infrared : public Motor {
private:
  unsigned long startTime;
  unsigned long endTime;
  int zeros;
public:
  Infrared();
  void activate(void);
  int getState(void);
  void backUp(void);
  void UTurn(void);
};

#endif
