#include <SoftwareSerial.h>
#include "Motor.h"
#include "Infrared.h"
#include "LineTracer.h"

// Create Object
Motor motor;
LineTracer lineTracer;
Infrared infrared;

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  lineTracer.activate();
}
