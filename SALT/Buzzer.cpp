#include "Buzzer.h"

void Buzzer::playCollide(void) {
  tone(BUZZER_PIN, A4, TEMPO);    
}

void Buzzer::playTurn(int i) {
  tone(BUZZER_PIN, A5, TEMPO);    
}