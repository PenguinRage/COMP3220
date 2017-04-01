#include "spaceitemfactory.h"



SpaceItem * SpaceItemFactory::make(
        SpaceTypes type,
        int posx,
        int posy,
        int speed,
        std::string size)
{
    if (type == DEFENDER) {
        return new Defender(posx, posy, speed, size);
    } else if (type == BULLET) {
        return new Bullet(posx, posy, speed);
    } else if (type == STAR) {
        return new Star(posx, posy, speed);
    }
    else {
        return nullptr;
    }
}
