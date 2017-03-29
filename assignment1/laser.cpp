#include "laser.h"

Laser::Laser(int posx, int posy, int speed) :
    lx(posx),
    ly(posy),
    ls(speed)
{
    laser.load(":/images/fireball.png");
}

Laser::~Laser(){}

QPixmap Laser::getLaser() {
    return this->laser;
}

// Get Methods
int Laser::getPosX() {
    return this->lx;
}

int Laser::getPosY() {
    return this->ly;
}

int Laser::getSpeed() {
    return this->ls;
}

// Set Methods
void Laser::setPosX(int x) {
    this->lx = x;
}

void Laser::setPosY(int y) {
    this->ly = y;
}

void Laser::setSpeed(int speed) {
    this->ls = speed;
}
