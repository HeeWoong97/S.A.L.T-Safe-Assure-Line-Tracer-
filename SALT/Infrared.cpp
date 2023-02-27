#include "Infrared.h"

extern int val_left_samples[];
extern int val_right_samples[];

bool is_something = false;

Infrared::Infrared()
{
  startTime = 0;
  endTime = 0;
  zeros = 0;  
  pinMode(INFRARED_PIN, INPUT);
}

void Infrared::activate(void)
{
  Serial.println("Infrared");
  int state = digitalRead(INFRARED_PIN);
  if (state == 0) {
    if (zeros <= 50) {
      zeros++;
    }
    if (zeros > 40) {
      is_something = true;
    }
  }
  else if (state == 1) {
    if (zeros > 0) {
      zeros--;
    }
    if (zeros <= 40) {
      is_something = false;
    }
  }

  if (is_something) {
    motor_L.run(RELEASE);
    motor_R.run(RELEASE);

    if (startTime == 0) {
      startTime = millis();
    }
    else {
      endTime = millis();
      if (endTime - startTime > INTERVAL) {
        backUp();
        UTurn();
        startTime = 0;
        endTime = 0;
      }
    }
  }
  else {
    startTime = 0;
    endTime = 0;
  }
}

void Infrared::backUp(void)
{
  motor_L.setSpeed(MOTOR_SPEED);
  motor_R.setSpeed(MOTOR_SPEED);
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
  delay(100);
}

void Infrared::UTurn(void)
{
  int leftCnt = 0;
  int rightCnt = 0;

  bool leftTurn = false;
  bool rightTurn = false;

  // 회전할 방향 정하기
  for (int i = 0; i < 10; i++) {
    if (val_left_samples[i] == 1) {
      leftCnt++;
    }    
    if (val_right_samples[i] == 1) {
      rightCnt++;
    }
  }

  // 왼쪽으로 돌기
  if (leftCnt > rightCnt) {
    leftPivotTurn();
    while (digitalRead(LEFT_SENSOR_PIN) == 0) {
      leftPivotTurn();
    }
  }
  // 오른쪽으로 돌기
  else {
    rightPivotTurn();
    while (digitalRead(RIGHT_SENSOR_PIN) == 0) {
      rightPivotTurn();
    }
  }
}