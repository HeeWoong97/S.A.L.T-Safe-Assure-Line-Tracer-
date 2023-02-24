#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Motor.h"

#define COLLISION_SENSOR    A2
#define BUZZER  9 
#define TONE    660 // 충돌 시 나오는 사운드

class Collision : public Motor {
private:
    int collisionValue;     // 충돌 센서의 값(~1019)
public:
    void activate();
    int readSensor();
};

#endif