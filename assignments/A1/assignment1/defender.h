#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "spaceitem.h"
#include <string>
#include <iostream>
#include <QPixmap>
#include <QBitmap>
#include <QColor>


class Defender : public SpaceItem
{

public:
    Defender(int posx, int posy, int speed, std::string size);
    ~Defender();
    QPixmap getDefender();
    int getSpeed();
    int getPosX();
    int getPosY();
    std::string getSize();
    void setSpeed(int speed);
    void setPosX(int x);
    void setPosY(int y);
    QPixmap setSize(std::string size);
    void setColor(QColor color);



protected:
    QPixmap defender;
    int ds = 3;
    int dx = 0;
    int dy = 350;
    std::string dsize;
};


#endif // SPACESHIP_H
