#ifndef STAR_H
#define STAR_H
#include "spaceitem.h"


class Star : public SpaceItem
{
public:
    Star(int posx, int posy, int speed=10);
    ~Star();
    int getSpeed();
    int getPosX();
    int getPosY();
    void setSpeed(int speed);
    void setPosX(int x);
    void setPosY(int y);
protected:
    int ss;
    int sy;
    int sx;
};

#endif // STAR_H
