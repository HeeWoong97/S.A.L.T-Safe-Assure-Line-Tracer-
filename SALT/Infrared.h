#ifndef _INFRARED_H_
#define _INFRARED_H_

#include <Arduino.h>
#include "Motor.h"

#define INFRARED_PIN    A4
#define INTERVAL        3000

class Infrared : public Motor {
private:
  int state;
  int curMotorSpeed;
  int startTime;
  int endTime;
public:
  Infrared();
  void activate(void);
  int getState(void);
  void backUp(void);
  void UTurn(void);
};

#endif
