#include "DotMatrix.h"

DotMatrix::DotMatrix() : lc(2, 10, 9, 1)
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
}

void DotMatrix::display(byte shape[])
{
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, shape);
  }
}