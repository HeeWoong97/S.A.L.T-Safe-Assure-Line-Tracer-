#ifndef _INFRARED_H_
#define _INFRARED_H_

#include "Motor.h"

#define INFRARED_PIN    A4

class Infrared : public Motor {
private:
    int state;
    int curMotorSpeed;
public:
    Infrared();
    void backUp(void);
    void UTurn(void);
};

#endif
