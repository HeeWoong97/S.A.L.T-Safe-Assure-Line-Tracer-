#include <SoftwareSerial.h>
#include "Motor.h"
#include "LineTracer.h"



// Create Object
Motor motor;
LineTracer lineTracer;

// Global Variable

static const int n = 10; // variable n for size of array for moving average filter
int val_left_samples[n] = {};
int val_right_samples[n] = {};


void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  lineTracer.activate();
}
