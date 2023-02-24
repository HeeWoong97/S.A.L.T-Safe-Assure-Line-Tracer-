#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

#define MOTOR_SPEED 180

class Motor {
protected:
    AF_DCMotor motor_L;
    AF_DCMotor motor_R;
public:
    Motor();
};

#endif