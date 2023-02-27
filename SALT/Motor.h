#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Arduino.h>

#define MOTOR_SPEED 180

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