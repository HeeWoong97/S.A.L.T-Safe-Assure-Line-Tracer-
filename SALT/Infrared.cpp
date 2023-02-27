#include "Infrared.h"

extern int val_left_samples[];

Infrared::Infrared()
{
    curMotorSpeed = MOTOR_SPEED;
    startTime = 0;
    endTime = 0;

    pinMode(INFRARED_PIN, INPUT);
}

void Infrared::activate(void)
{
  int state = digitalRead(INFRARED_PIN);

  if (state == 0) {
    motor_L.run(RELEASE);
    motor_R.run(RELEASE);

    if (startTime = 0) {
      startTime = millis();
    }
    else {
      endTime = millis();
      if (endTime - startTime > INTERVAL) {
        backUp();
        UTurn();
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

}