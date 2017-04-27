#include "star.h"

Star::Star(int posx, int posy, int speed) : ss(speed), sx(posx), sy(posy){}

Star::~Star()
{

}

// Get Methods

int Star::getPosX() {
    return this->sx;
}

int Star::getPosY() {
    return this->sy;
}

int Star::getSpeed() {
    return this->ss;
}

// Set Methods
void Star::setPosX(int x) {
    this->sx = x;
}

void Star::setPosY(int y) {
    this->sy = y;
}

void Star::setSpeed(int speed) {
    this->ss = speed;
}
