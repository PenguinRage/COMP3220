#include "number.h"
#include "octal.h"

string Number::type = "decimal";
Number *Number::inst = 0;

Number::Number()
{
    Number * Number::instance()
    {
      if (!inst)
        // 3. Do "lazy initialization" in the accessor function
        if (type == "octal")
          inst = new Octal();
        else
          inst = new Number();
      return inst;
    }
}
