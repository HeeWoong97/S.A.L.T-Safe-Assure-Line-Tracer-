#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <Arduino.h>

#define BUZZER_PIN  13
#define TEMPO       100

#define A4 2273 // 440.11Hz 라
#define A5 1136 // 880.11Hz 라

class Buzzer {
public:
  void playCollide(void);
  void playTurn(int);
};

#endif