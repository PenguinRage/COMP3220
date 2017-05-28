#include "mouse.h"

namespace game {
void MOUSE::keyboard(Controller *c)
{
    cout << "   going from mouse to keyboard";
    c->setCurrent(new KEYBOARD());
    delete this;
}
}

