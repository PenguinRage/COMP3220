#include "spaceitemfactory.h"



SpaceItem * SpaceItemFactory::make(SpaceTypes type, int posx, int posy, int speed)
{
    if (type == SPACESHIP)
    {
        return new SpaceShip(posx, posy, speed);

    } else if (type == LASER) {
        return new Laser(posx, posy, speed);
    }
    else {
        return nullptr;
    }
}
