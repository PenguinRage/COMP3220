#include "spaceship.h"

SpaceShip::SpaceShip(int posx, int posy, int speed) :
    dx(posx),
    dy(posy),
    ds(speed)
{
    defender.load(":/images/defender.png");
}

SpaceShip::~SpaceShip(){}

QPixmap SpaceShip::getDefender() {
    return this->defender;
}

// Get Methods
int SpaceShip::getPosX() {
    return this->dx;
}

int SpaceShip::getPosY() {
    return this->dy;
}

int SpaceShip::getSpeed() {
    return this->ds;
}

// Set Methods
void SpaceShip::setPosX(int x) {
    this->dx = x;
}

void SpaceShip::setPosY(int y) {
    this->dy = y;
}

void SpaceShip::setSpeed(int speed) {
    this->ds = speed;
}
