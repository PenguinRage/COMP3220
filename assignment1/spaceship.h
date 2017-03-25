#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <string>
#include <iostream>

namespace si {
class Spaceship
{

public:
    Spaceship() {}

protected:
    std::string size;
    int ds;
    int dx;
    int dy;
};
}

#endif // SPACESHIP_H
