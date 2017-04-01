#include <iostream>
#include "battlesphere.h"
#include "config.h"
#include "spaceitemfactory.h"
#include <QKeyEvent>

using namespace std;



// Easy way to setup on Windows || Linux
string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";

namespace si {
BattleSphere::BattleSphere(QWidget *parent) : QDialog(parent), sound(":/sounds/explosion_x.wav") {
    // Timer setup
    timer = new QTimer(this);
    // Create Config instance
    config = Config::getInstance();
    // Config PATH directory to global variable filename
    config->setAbsolutePath(CONFIG_PATH);
    //Config Load data from config
    config->load();
    // Get the commands for the application
    commands = config->getCommands("commands");
    // Use of Factory Method
    ship = (Defender *) factory.make(DEFENDER,config->getNumber("defenderx"),config->getNumber("defendery"),config->getNumber("defenders"), config->getValue("size"));
    // assign global variables values from ship class.
    dx = ship->getPosX();
    dy = ship->getPosY();
    ds = ship->getSpeed();

    try {
        setStyleSheet("background-color: #000000;");
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
    config->destroy();
    delete ship;
    delete timer;
}

void BattleSphere::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(dx, dy, ship->getDefender());


    for (int i = 0; i < (signed) bullets.size(); i++)
    {
        Bullet * bullet = bullets[i];
        painter.drawPixmap(bullet->getPosX(), bullet->getPosY(), bullet->getBullet());
    }
}

void BattleSphere::spaceshipCommand() {
    string command = commands[counter];
    // Adding borders to the game -> no out of bounds
    int ship_width = ship->getDefender().width()/2;
    // Adding borders to the game -> no out of bounds
    int maxX = this->width()-ship_width;

    // Commands to operate the Spaceship Defender
    if (!command.compare("LEFT") && dx > ship_width){
        dx -= ds;
    }
    else if (!command.compare("RIGHT") && dx < maxX) {
        dx += ds;
    } else if (!command.compare("FIRE")) {
        Bullet * laser = (Bullet *) factory.make(BULLET, -1000, -1000, 3);
        bullets.push_back(laser);
    }

}

void BattleSphere::nextFrame() {
    if (gamerunner) {
        int ship_width = ship->getDefender().width()/2;
        // check when to finish frame capture
        if (counter >= (signed) commands.size() && bullets.size() == 0)
        {
            timer->stop();
            return;
        }

        // SpaceShip must make a choice :O
        if (counter < (signed) commands.size()) {
            spaceshipCommand();
        }

        for (int i =0; i < (signed) bullets.size(); i++)
        {
            Bullet * bullet = bullets[i];
            int by = bullet->getPosY();
            int bx = bullet->getPosX();
            int bs = bullet->getSpeed();
            // shoot or animate the bullet
            if(by <= -100){
                bx = dx + (ship_width/2) - (bullet->getBulletWidth()/2);
                by = dy - bullet->getBulletHeight();
                sound.play();
            } else {
                by -= bs;
            }
            bullet->setPosX(bx);
            bullet->setPosY(by);

            if (bullet->getPosY() < 0) {
                delete bullet;
                bullets.erase(bullets.begin()+i);
            }
        }

        counter++;
        update();
    }
}

// sets the ship as a global from our class
void BattleSphere::setDefender(Defender * ship) {
    this->ship = ship;
}

// Pauses the game when P is pressed
void BattleSphere::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_P) {
        if (gamerunner) {
            cout << "Paused" << endl;
        }
        else {
            cout << "Unpaused" << endl;
        }
        togglePause();
    }
}
// Is the game paused or unpaused true = unpaused
void BattleSphere::togglePause() {
    gamerunner = !gamerunner;
}

} // end namespace si

