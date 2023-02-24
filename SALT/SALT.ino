#include <SoftwareSerial.h>
#include "Motor.h"

#include "Collision.h"
#include "Infrared.h"
#include "LineTracer.h"

// Create Object
Motor motor;
Collision collision;
Infrared infrared;
LineTracer lineTracer;

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  lineTracer.activate();
  collision.activate();
}
