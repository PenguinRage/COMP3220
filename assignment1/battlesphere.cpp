#include <iostream>
#include "battlesphere.h"
#include "config.h"

using namespace std;


namespace si {
// Easy way to setup on Windows || Linux
string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";

BattleSphere::BattleSphere(QWidget *parent) : QDialog(parent), sound(":/sounds/explosion_x.wav") {

        // Create Config instance
        config = Config::get_instance();
        // Config PATH directory to global variable filename
        config->set_absolute_path(CONFIG_PATH);
        // Config Load data from config
        config->load();
        // Timer setup
        timer = new QTimer(this);

        try {
            setStyleSheet("background-color: #000000;");
            defender.load(":/images/defender.png");
            bullet.load(":/images/fireball.png");
            this->resize(600, 400);
            update();
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start(32);
        } catch (string error) {
            cout << error << endl;
            delete timer;
            config->destroy();
            exit(1);
        }
    }

    BattleSphere::~BattleSphere() {
        delete timer;
        config->destroy();
    }

    void BattleSphere::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.drawPixmap(dx, dy, defender);
        painter.drawPixmap(bx, by, bullet);
    }

    void BattleSphere::nextFrame() {
        // animate the defender
        int maxX = this->width()-defender.width();
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
            bx = dx + (defender.width()/2) - (bullet.width()/2);
            by = dy - bullet.height();
            sound.play();
        } else {
            by -= bs;
        }

        update();
    }

    // Validation for Integers returns false to throw error
    bool BattleSphere::validateInt(const string input) {
        // The number of negative signs in string
        int negative_count =count(input.begin(), input.end(), '-');
        // if only '-'
        if((signed int) input.size() == negative_count) return false;
        // if '---1'
        else if (negative_count > 1) return false;
        //if negative sign is in wrong place
        else if (negative_count == 1 && input[0] != '-') return false;
        // The string contains a character that isn't within "-0123456789"
        else if (strspn(input.c_str(), "-0123456789") != input.size()) return false;
        return true;
    }

    int BattleSphere::getNumber(string key) {
        string value = config->get_value(key);

        if (validateInt(value)) {
            return (int) strtod(value.c_str(), NULL);
        } else throw "The value for key: \"" + key + "\" should be a number. ";
    }


} // end namespace si

