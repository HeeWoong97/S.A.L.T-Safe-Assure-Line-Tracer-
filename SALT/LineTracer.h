#ifndef _LINETRACER_H_
#define _LINETRACER_H_

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <AFMotor.h>

#include "Motor.h"

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
  static const int n = 10;
  int val1;
  int val2;
  int val1_samples[n];
  int val2_samples[n];
  int val1_sum;
  int val2_sum;
  int val1_index;
  int val2_index;
  AF_DCMotor motor_L;
  AF_DCMotor motor_R;
public:
  LineTracer();
  void setup();
  void loop();
};

#endif