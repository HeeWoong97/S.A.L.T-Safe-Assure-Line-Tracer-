#ifndef _LINETRACER_H_
#define _LINETRACER_H_

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <AFMotor.h>

#include "Motor.h"

#define N   10

extern int val_left_samples[N];
extern int val_right_samples[N];

class LineTracer : public Motor {
private:

  // Functions
  void readSensors();
  void updateSampleArrays();
  int calculateMovingAverage(int samples[], int sum);
  void followLine(int val1_avg, int val2_avg);
  void goForward();
  void turnRight();
  void turnLeft();
  void randomTurn();
  
  // Variables  

  int val_left;
  int val_right;
  
  int val_left_sum;
  int val_right_sum;
  int val_left_index;
  int val_right_index;
  AF_DCMotor motor_L;
  AF_DCMotor motor_R;
public:

  LineTracer();
  void setup();
  void activate();
};

#endif
