#include "DotMatrix.h"

byte smile[8] = {
  B00111100,
  B01000010,
  B10101001,
  B10000101,
  B10000101,
  B10101001,
  B01000010,
  B00111100
};

byte sad[8] = {
B00111100,
B01000010,
B10100101,
B10001001,
B10001001,
B10100101,
B01000010,
B00111100
};

DotMatrix::DotMatrix() : lc(2, 10, 9, 1)
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);

  shapes[SMILE] = smile;
  shapes[SAD] = sad;  
}

void DotMatrix::displaySmile(void)
{
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, shapes[SMILE]);
  }
}

void DotMatrix::displaySad(void)
{
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, shapes[SAD]);
  }
}