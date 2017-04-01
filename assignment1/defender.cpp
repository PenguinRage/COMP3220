#include "defender.h"
// Defender class
Defender::Defender(int posx, int posy, int speed, std::string size) :
    dx(posx),
    dy(posy),
    ds(speed)
{
    defender = setSize(size);
}

Defender::~Defender(){}

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

QPixmap Defender::getDefender() {
    return this->defender;
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

QPixmap Defender::setSize(std::string size){
    QPixmap image;
    image.load(":/images/defender.png");

    this->dsize = size;
    if (!size.compare("normal") || !size.compare("NORMAL")) {
        return image;
    }
    else if (!size.compare("tiny") || !size.compare("TINY")) {
        image = image.scaledToWidth(image.width()/2);
        return image;
    }
    else if (!size.compare("large") || !size.compare("LARGE")) {
        image = image.scaledToWidth(image.width()*2);
        return image;
    }
    else if (!size.compare("giant") || !size.compare("GIANT")) {
        image = image.scaledToWidth(image.width()*3);
        return image;
    } else {
        throw "Value of \"size\" was not given correctly in config file!";
    }
}

