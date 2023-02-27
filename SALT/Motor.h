#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <SoftwareSerial.h>
#include <AFMotor.h>

#define MOTOR_SPEED 180

class Motor {
protected:
    AF_DCMotor motor_L;
    AF_DCMotor motor_R;
public:
<<<<<<< Updated upstream
    Motor();
=======
  Motor();
  void turnLeft(void);
  void turnRight(void);
  void leftPivotTurn(void);
  void rightPivotTurn(void);
  void delay_ms(unsigned long milliseconds);
>>>>>>> Stashed changes
};

#endif
