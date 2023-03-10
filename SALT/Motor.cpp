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
  delay_ms(MOTOR_DELAY);
  motor_L.run(RELEASE);
  motor_R.run(FORWARD);
  delay_ms(MOTOR_DELAY);
}

void Motor::turnRight(void)
{
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
  delay_ms(MOTOR_DELAY);
  motor_L.run(FORWARD);
  motor_R.run(RELEASE);
  delay_ms(MOTOR_DELAY);  
}

void Motor::leftPivotTurn(void)
{
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay_ms(MOTOR_DELAY);
}

void Motor::rightPivotTurn(void)
{
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
  delay_ms(MOTOR_DELAY);
}

void Motor::delay_ms(unsigned long milliseconds)
{
  unsigned long startTime = millis();

  while (millis() - startTime < milliseconds) {
    // Do nothing, just wait for the specified delay_ms
    }
}
