#ifndef LINE_TRACER_H
#define LINE_TRACER_H

#include <SoftwareSerial.h>
#include <Arduino.h>

#include <AFMotor.h>

class LineTracer {
public:
  LineTracer();
  void setup();
  void loop();

private:
  LineTracer();

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
};

#endif
