#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Motor.h"
#include "Buzzer.h"
#include "DotMatrix.h"
#include "Buzzer.h"
#define COLLISION_SENSOR    A2
#define BUZZER  9 
#define TONE    660 // 충돌 시 나오는 사운드

class Collision : public Motor {
private:
    int collisionValue;     // 충돌 센서의 값(~1019)
    DotMatrix dotMatrix;
    Buzzer buzzer;
public:
    Collision();
    void activate();
    int readSensor();
};

#endif
