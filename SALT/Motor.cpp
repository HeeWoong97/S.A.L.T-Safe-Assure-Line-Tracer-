#include "Motor.h"

Motor::Motor() : motor_L(1), motor_R(4)
{
  motor_L.setSpeed(MOTOR_SPEED);
  motor_L.run(RELEASE);
  motor_R.setSpeed(MOTOR_SPEED);
  motor_R.run(RELEASE);
}