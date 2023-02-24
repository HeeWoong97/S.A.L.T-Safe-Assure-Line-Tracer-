#include <SoftwareSerial.h>
#include "Motor.h"
#include "Collision.h"

Collision collision;

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  collision.activate();
}
