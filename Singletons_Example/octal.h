#ifndef OCTAL_H
#define OCTAL_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "number.h"
#include "octal.h"
class Octal: public Number
{
  // 6. Inheritance can be supported
  public:
    friend class Number;
    void setValue(int in)
    {
      char buf[10];
      sprintf(buf, "%o", in);
      sscanf(buf, "%d", &value);
    }
  protected:
    Octal(){}
};
#endif // OCTAL_H
