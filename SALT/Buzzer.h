#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <Arduino.h>

#define BUZZER_PIN  13
#define TEMPO       200

#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 

class Buzzer {
private:

public:
  void playDo(void);
  void playRe(void);
  void playMi(void);
  void playFa(void);
  void playSol(void);
  void playRa(void);
  void playSi(void);
};

#endif