#include "Motor.h"

Motor::Motor() : motor_L(1), motor_R(4)
{
  motor_L.setSpeed(MOTOR_SPEED);
  motor_L.run(RELEASE);
  motor_R.setSpeed(MOTOR_SPEED);
  motor_R.run(RELEASE);
}

void Motor::turnLeft(void)
{
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay(20);
  motor_L.run(RELEASE);
  motor_R.run(FORWARD);
  delay(60);
}

void Motor::turnRight(void)
{
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
  delay(20);
  motor_L.run(FORWARD);
  motor_R.run(RELEASE);
  delay(60);  
}

void Motor::leftPivotTurn(void)
{
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay(20);
}

void Motor::rightPivotTurn(void)
{
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
  delay(20);
}