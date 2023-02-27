#ifndef _DOT_MATRIX_H_
#define _DOT_MATRIX_H_

#include <Arduino.h>
#include "LedControl.h"

class DotMatrix {
private:
  LedControl lc;
public:
  DotMatrix();
  void display(byte shape[]);
};

#endif