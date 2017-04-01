#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "spaceitem.h"
#include <string>
#include <iostream>
#include <QPixmap>


class Defender : public SpaceItem
{

public:
    Defender(int posx, int posy, int speed, std::string size);
    ~Defender();
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
    int dx = 0;
    int dy = 350;
    int ds = 3;
    std::string dsize;
};


#endif // SPACESHIP_H
