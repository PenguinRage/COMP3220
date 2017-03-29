#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "spaceitem.h"
#include <string>
#include <iostream>
#include <QPixmap>


class SpaceShip : public SpaceItem
{

public:
    SpaceShip(int posx, int posy, int speed);
    ~SpaceShip();
    QPixmap getDefender();
    int getSpeed();
    int getPosX();
    int getPosY();
    void setSpeed(int speed);
    void setPosX(int x);
    void setPosY(int y);


protected:
    std::string size;
    QPixmap defender;
    int ds;
    int dx;
    int dy;
};


#endif // SPACESHIP_H
