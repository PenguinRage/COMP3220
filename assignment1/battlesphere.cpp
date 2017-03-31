#include <iostream>
#include "battlesphere.h"
#include "config.h"
#include "spaceitemfactory.h"
using namespace std;



// Easy way to setup on Windows || Linux
string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";

namespace si {
BattleSphere::BattleSphere(QWidget *parent) : QDialog(parent), sound(":/sounds/explosion_x.wav") {
        // Timer setup
        timer = new QTimer(this);
        // Create Config instance
        config = Config::get_instance();
        // Config PATH directory to global variable filename
        config->set_absolute_path(CONFIG_PATH);
        //Config Load data from config
        config->load();
        // Get the commands for the application
        commands = config->getCommands("commands");
        // Use of Factory Method
        ship = (SpaceShip *) factory.make(SPACESHIP,config->getNumber("defenderx"),config->getNumber("defendery"),config->getNumber("defenders"));

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
        config->destroy();
        delete ship;
        delete timer;
    }

    void BattleSphere::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.drawPixmap(dx, dy, ship->getDefender());
        painter.drawPixmap(bx, by, bullet);
    }

    void BattleSphere::spaceshipCommand() {
        string command = commands[counter];
        // Adding borders to the game -> no out of bounds
        int ship_width = ship->getDefender().width()/2;
        // Adding borders to the game -> no out of bounds
        int maxX = this->width()-ship_width;
        if (!command.compare("LEFT") && dx > ship_width){
            cout << command << endl;
            dx -= ds;
        }
        else if (!command.compare("RIGHT") && dx < maxX) {
            dx += ds;
        }

    }

    void BattleSphere::nextFrame() {
        int ship_width = ship->getDefender().width()/2;
        // check when to finish frame capture
        if (counter == (signed) commands.size())
        {
            timer->stop();
            return;
        }

        // SpaceShip must make a choice :O
        spaceshipCommand();


/*
        int ship_width = ship->getDefender().width();
        int maxX = this->width()-ship_width;
        dx += ds;
        if(dx >= maxX){
            dx = (2*maxX)-dx;
            ds *= -1;
        } else if (dx <= 0) {
            dx *= -1;
            ds *= -1;
        }
*/
        // shoot or animate the bullet
        if(by <= -100){
            bx = dx + (ship_width/2) - (bullet.width()/2);
            by = dy - bullet.height();
            //sound.play();
        } else {
            by -= bs;
        }
        counter++;
        update();
    }

    void BattleSphere::setDefender(SpaceShip * ship) {
        this->ship = ship;
    }


} // end namespace si

