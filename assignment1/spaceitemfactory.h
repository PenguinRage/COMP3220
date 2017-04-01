#ifndef SPACEITEMFACTORY_H
#define SPACEITEMFACTORY_H
#include "spaceitem.h"
#include "defender.h"
#include "bullet.h"
#include <iostream>

enum SpaceTypes { DEFENDER, BULLET };

class SpaceItemFactory
{

public:
    SpaceItemFactory(){}
    ~SpaceItemFactory(){}
    SpaceItem * make(SpaceTypes type, int posx, int posy, int speed, std::string size = "normal");
};

#endif // SPACEITEMFACTORY_H
