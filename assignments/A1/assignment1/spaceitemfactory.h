#ifndef SPACEITEMFACTORY_H
#define SPACEITEMFACTORY_H
#include "spaceitem.h"
#include "defender.h"
#include "bullet.h"
#include "star.h"
#include <iostream>

enum SpaceTypes { DEFENDER, BULLET, STAR };

class SpaceItemFactory
{

public:
    SpaceItemFactory(){}
    ~SpaceItemFactory(){}
    SpaceItem * make(SpaceTypes type, int posx, int posy, int speed, std::string size = "normal");
};

#endif // SPACEITEMFACTORY_H
