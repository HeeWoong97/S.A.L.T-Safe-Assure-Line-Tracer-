#include "LineTracer.h"
#include <Arduino.h>
#include <AFMotor.h>

// SALT.ino에 선언된 전역변수 가져오기
int val_left_samples[N];
int val_right_samples[N];

LineTracer::LineTracer(): motor_L(1), motor_R(4){


  // Initialize the sensor variables
  val_left = 0;
  val_right = 0;
  val_left_sum = 0;
  val_right_sum = 0;
  val_left_index = 0;
  val_right_index = 0;
  
}

//void LineTracer::setup() {
//  // Initialize the motor objects
//  motor_L.setSpeed(0);
//  motor_R.setSpeed(0);
//}


void LineTracer::activate() {
  DotMatrix dotMatrix;

  // dotMatrix.displaySmile();

  readSensors();
  updateSampleArrays();
  int val_left_avg = calculateMovingAverage(val_left_samples, val_left_sum);
  int val_right_avg = calculateMovingAverage(val_right_samples, val_right_sum);
  followLine(val_left_avg, val_right_avg);
}

void LineTracer::readSensors() {
  val_left = digitalRead(A0);
  val_right = digitalRead(A5);
}

void LineTracer::updateSampleArrays() {
  val_left_sum = val_left_sum - val_left_samples[val_left_index] + val_left;
  val_right_sum = val_right_sum - val_right_samples[val_right_index] + val_right;
  val_left_samples[val_left_index] = val_left;
  val_right_samples[val_right_index] = val_right;
  val_left_index = (val_left_index + 1) % N;
  val_right_index = (val_right_index + 1) % N;
}

int LineTracer::calculateMovingAverage(int samples[], int sum) {
  int avg = sum / N;
  return avg;
}

void LineTracer::followLine(int val_left_avg, int val_right_avg) {
  if (val_left_avg == 0 && val_right_avg == 0) { 
    goForward();
  } 
  else {
    motor_L.setSpeed(225);
    motor_R.setSpeed(225);
    if (val_left_avg == 0 && val_right_avg == 1) {
      turnRight();
    } else if (val_left_avg == 1 && val_right_avg == 0) {
      turnLeft();
    } else if (val_left_avg == 1 && val_right_avg == 1) {
      // randomTurn();
    }
  }
}

void LineTracer::goForward() {
  motor_L.setSpeed(180);
  motor_R.setSpeed(180);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void LineTracer::randomTurn() {
  int direction = random(0,2);
//  if (direction == 0){
//    motor_L.run(BACKWARD);
//    motor_R.run(FORWARD);
//  } else {
//    motor_L.run(FORWARD);
//    motor_R.run(BACKWARD);
//  }
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay(200);  
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
  delay(500);
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  delay(200);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
  delay(500);
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  delay(200);
}
