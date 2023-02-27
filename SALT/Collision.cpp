#include "Collision.h"

int Collision::readSensor() {
    return analogRead(COLLISION_SENSOR);
}

void Collision::activate() {
  Serial.println("Collision");
    collisionValue = readSensor();
    Serial.println(collisionValue);
    if (collisionValue < 200)   // 충돌 감지
    {
        Buzzer buzzer;
        motor_L.run(RELEASE);
        motor_R.run(RELEASE);
        buzzer.playSi();
        delay_ms(500);
    }
}
