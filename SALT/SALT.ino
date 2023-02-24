#include <SoftwareSerial.h>
#include "Motor.h"
#include "LineTracer.h"

// Create Object
Motor motor;
LineTracer lineTracer;

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  lineTracer.loop();
}
