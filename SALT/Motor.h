#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

#define MOTOR_SPEED 255
#define MOTOR_SPEED_TURN 225
#define MOTOR_DELAY 10

class Motor {
protected:
  AF_DCMotor motor_L;
  AF_DCMotor motor_R;
public:
  Motor();
  void turnLeft(void);
  void turnRight(void);
  void leftPivotTurn(void);
  void rightPivotTurn(void);
  void delay_ms(unsigned long milliseconds);
};

#endif
