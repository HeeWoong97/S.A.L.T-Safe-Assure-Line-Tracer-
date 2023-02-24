#include "LineTracer.h"
#include <Arduino.h>
#include <AFMotor.h>

LineTracer::LineTracer(): motor_L(1), motor_R(4){


  // Initialize the sensor variables
  val1 = 0;
  val2 = 0;
  val1_sum = 0;
  val2_sum = 0;
  val1_index = 0;
  val2_index = 0;
  for (int i = 0; i < n; i++) {
    val1_samples[i] = 0;
    val2_samples[i] = 0;
  }
}

//void LineTracer::setup() {
//  // Initialize the motor objects
//  motor_L.setSpeed(0);
//  motor_R.setSpeed(0);
//}


void LineTracer::activate() {
  readSensors();
  updateSampleArrays();
  int val1_avg = calculateMovingAverage(val1_samples, val1_sum);
  int val2_avg = calculateMovingAverage(val2_samples, val2_sum);
  followLine(val1_avg, val2_avg);
}

void LineTracer::readSensors() {
  val1 = digitalRead(A0);
  val2 = digitalRead(A5);
}

void LineTracer::updateSampleArrays() {
  val1_sum = val1_sum - val1_samples[val1_index] + val1;
  val2_sum = val2_sum - val2_samples[val2_index] + val2;
  val1_samples[val1_index] = val1;
  val2_samples[val2_index] = val2;
  val1_index = (val1_index + 1) % n;
  val2_index = (val2_index + 1) % n;
}

int LineTracer::calculateMovingAverage(int samples[], int sum) {
  int avg = sum / n;
  return avg;
}

void LineTracer::followLine(int val1_avg, int val2_avg) {
  if (val1_avg == 0 && val2_avg == 0) { 
    goForward();
  } 
  else {
    motor_L.setSpeed(225);
    motor_R.setSpeed(225);
    if (val1_avg == 0 && val2_avg == 1) {
      turnRight();
    } else if (val1_avg == 1 && val2_avg == 0) {
      turnLeft();
    } else if (val1_avg == 1 && val2_avg == 1) {
      randomTurn();
    }
  }
}

void LineTracer::goForward() {
  motor_L.setSpeed(180);
  motor_R.setSpeed(180);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void LineTracer::turnRight() {
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
  delay(20);
  motor_L.run(FORWARD);
  motor_R.run(RELEASE);
  delay(60);
}

void LineTracer::turnLeft() {
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay(20);
  motor_L.run(RELEASE);
  motor_R.run(FORWARD);
  delay(60);
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
