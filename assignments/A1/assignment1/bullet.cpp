#include "bullet.h"
// Bullet Class
Bullet::Bullet(int posx, int posy, int speed) :
    lx(posx),
    ly(posy),
    ls(speed)
{
    bullet.load(":/images/fireball.png");
}

Bullet::~Bullet(){}

QPixmap Bullet::getBullet() {
    return this->bullet;
}
int Bullet::getBulletWidth() {
    return this->getBullet().width();
}

int Bullet::getBulletHeight() {
    return this->getBullet().height();
}

// Get Methods
int Bullet::getPosX() {
    return this->lx;
}

int Bullet::getPosY() {
    return this->ly;
}

int Bullet::getSpeed() {
    return this->ls;
}

// Set Methods
void Bullet::setPosX(int x) {
    this->lx = x;
}

void Bullet::setPosY(int y) {
    this->ly = y;
}

void Bullet::setSpeed(int speed) {
    this->ls = speed;
}
