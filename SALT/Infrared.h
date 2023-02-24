#ifndef _INFRARED_H_
#define _INFRARED_H_

#include <Arduino.h>
#include "Motor.h"

#define LEFT_SENSOR_PIN   A0
#define RIGHT_SENSOR_PIN  A5
#define INFRARED_PIN      A4

#define INTERVAL        3000

class Infrared : public Motor {
private:
  int curMotorSpeed;
  int startTime;
  int endTime;
public:
  Infrared();
  void activate(void);
  int getState(void);
  void backUp(void);
  void turnLeft(void);
  void turnRight(void);
  void UTurn(void);
};

#endif
