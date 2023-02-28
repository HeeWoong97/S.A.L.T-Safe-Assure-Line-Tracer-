#include "Collision.h"
#include "DotMatrix.h"

bool is_collide = false;

Collision::Collision()
{
  pinMode(COLLISION_SENSOR, INPUT);
}

int Collision::readSensor() {
    return analogRead(COLLISION_SENSOR);
}

void Collision::activate() {
    collisionValue = readSensor();
    Serial.println(collisionValue);
    if (collisionValue < 500)   // 충돌 감지
    {
        is_collide = true;
        buzzer.playCollide();
        dotMatrix.displaySad();
        delay_ms(1000);
    }
    if (collisionValue > 900) {
        dotMatrix.displaySmile();
    }
}
