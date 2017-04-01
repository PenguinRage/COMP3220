#include "defender.h"
// Defender class
Defender::Defender(int posx, int posy, int speed, std::string size) :
    dx(posx),
    dy(posy),
    ds(speed),
    dsize(size)
{
    defender.load(":/images/defender.png");

}

Defender::~Defender(){}

QPixmap Defender::getDefender() {
    return this->defender;
}

// Get Methods
int Defender::getPosX() {
    return this->dx;
}

int Defender::getPosY() {
    return this->dy;
}

int Defender::getSpeed() {
    return this->ds;
}

// Set Methods
void Defender::setPosX(int x) {
    this->dx = x;
}

void Defender::setPosY(int y) {
    this->dy = y;
}

void Defender::setSpeed(int speed) {
    this->ds = speed;
}
