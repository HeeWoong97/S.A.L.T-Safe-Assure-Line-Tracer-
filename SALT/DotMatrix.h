#ifndef _DOT_MATRIX_H_
#define _DOT_MATRIX_H_

#include <Arduino.h>
#include "LedControl.h"

#define SMILE   0
#define SAD     1

class DotMatrix {
private:
  LedControl lc;
  byte* shapes[2];
public:
  DotMatrix();
  void displaySmile(void);
  void displaySad(void);
};

#endif