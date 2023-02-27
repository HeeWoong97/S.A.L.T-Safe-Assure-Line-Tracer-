#include "Buzzer.h"

Buzzer::Buzzer()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void Buzzer::playDo(void)
{
  tone(BUZZER_PIN, C, TEMPO);
  delay(300);
}

void Buzzer::playRe(void)
{
  tone(BUZZER_PIN, D, TEMPO);
  delay(300);
}

void Buzzer::playMi(void)
{
  tone(BUZZER_PIN, E, TEMPO);
  delay(300);
}

void Buzzer::playFa(void)
{
  tone(BUZZER_PIN, F, TEMPO);
  delay(300);
}

void Buzzer::playSol(void)
{
  tone(BUZZER_PIN, G, TEMPO);
  delay(300);
}

void Buzzer::playRa(void)
{
  tone(BUZZER_PIN, A, TEMPO);
  delay(300);
}

void Buzzer::playSi(void)
{
  tone(BUZZER_PIN, B, TEMPO);
  delay(300);
}