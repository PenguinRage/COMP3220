#include "itemfactory.h"
#include "spaceitem.h"

#include <QGraphicsItem>

using namespace std;


SpaceItem * ItemFactory::make(SpaceAssetType type, Config * config) {
    if (type == SPACESHIP)
    {
        return nullptr;
    }
    else if (type == LASER)
    {
        return nullptr;
    }
    else
    {
        return nullptr;
    }
}
