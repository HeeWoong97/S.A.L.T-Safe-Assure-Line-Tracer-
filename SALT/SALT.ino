#include <SoftwareSerial.h>
#include "Motor.h"

#include "Collision.h"
#include "Infrared.h"
#include "LineTracer.h"
#include "DotMatrix.h"

// Create Object
Motor motor;
Collision collision;
Infrared infrared;
LineTracer lineTracer;
DotMatrix dotMatrix;
Buzzer buzzer;

extern bool is_something;
bool before_state;

void setup(void)
{
  Serial.begin(9600);
  dotMatrix.displaySmile();
  before_state = is_something;
}

void loop(void)
{
  if (is_something != before_state) {
    if (is_something == true) {
      dotMatrix.displaySad();
      buzzer.playSi();
    }
    else {
      dotMatrix.displaySmile();
    }
    before_state = is_something;
  }
  // collision.activate();
  infrared.activate();
  if (!is_something) {
    lineTracer.activate();
  }
}
