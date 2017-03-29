#ifndef SPACEITEMFACTORY_H
#define SPACEITEMFACTORY_H
#include "spaceitem.h"
#include "spaceship.h"
#include <iostream>

enum SpaceTypes { SPACESHIP, LASER };

class SpaceItemFactory
{

public:
    SpaceItemFactory(){}
    ~SpaceItemFactory(){}
    SpaceItem * make(SpaceTypes type, int posx, int posy, int speed);
};

#endif // SPACEITEMFACTORY_H
