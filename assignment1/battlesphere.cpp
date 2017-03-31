#include <iostream>
#include "battlesphere.h"
#include "config.h"

using namespace std;


namespace si {
BattleSphere::BattleSphere(QWidget *parent) : QDialog(parent), sound(":/sounds/explosion_x.wav") {
        // Timer setup
        timer = new QTimer(this);

        try {
            setStyleSheet("background-color: #000000;");

            bullet.load(":/images/fireball.png");
            this->resize(600, 400);
            update();
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start(32);
        } catch (string error) {
            cout << error << endl;
            delete timer;
            exit(1);
        }
    }

    BattleSphere::~BattleSphere() {
        delete timer;
    }

    void BattleSphere::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.drawPixmap(dx, dy, ship->getDefender());
        painter.drawPixmap(bx, by, bullet);
    }

    void BattleSphere::nextFrame() {
        // animate the defender
        int maxX = this->width()-ship->getDefender().width();
        dx += ds;
        if(dx >= maxX){
            dx = (2*maxX)-dx;
            ds *= -1;
        } else if (dx <= 0) {
            dx *= -1;
            ds *= -1;
        }

        // shoot or animate the bullet
        if(by <= -100){
            bx = dx + (ship->getDefender().width()/2) - (ship->getDefender().width()/2);
            by = dy - bullet.height();
            //sound.play();
        } else {
            by -= bs;
        }

        update();
    }

    void BattleSphere::setDefender(SpaceShip * ship) {
        this->ship = ship;
    }


} // end namespace si

