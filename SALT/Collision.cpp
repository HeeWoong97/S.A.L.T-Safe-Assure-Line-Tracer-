#include "Collision.h"

int Collision::readSensor() {
    return analogRead(COLLISION_SENSOR);
}

void Collision::activate() {
    collisionValue = readSensor();
    Serial.println(collisionValue);
    if (collisionValue < 900)   // 충돌 감지
    {
        analogWrite(BUZZER, TONE);
        delay_ms(50);
    }
    else
    {
        analogWrite(BUZZER, 0);
    }
}