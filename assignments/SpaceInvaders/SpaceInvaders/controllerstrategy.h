#ifndef CONTROLLERSTATE_H
#define CONTROLLERSTATE_H

#include <iostream>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSound>
#include <vector>

#include "ship.h"

namespace game {

class InputStrategy {
public:
    InputStrategy() {};
    virtual ~InputStrategy() {};
    QString name;

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins)=0;
};


class DefaultStrategy : public InputStrategy {
public:
    DefaultStrategy() { name = "default"; };
    ~DefaultStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins)
    {
        if (ins == "Left") {
            ship->move_left();

        } else if (ins == "Right") {
            ship->move_right();

        } else if (ins == "Shoot") {
            bullets->push_back(ship->shoot());
            shipFiringSound->play();
        }
    }
};


class KeyboardStrategy : public InputStrategy {
public:
    KeyboardStrategy() { name = "keyboard"; };
    ~KeyboardStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins)
    {
        QKeyEvent *k = (QKeyEvent *)event;
        if (k->key() == Qt::Key_Space) {
            bullets->push_back(ship->shoot());
            shipFiringSound->play();
        }

        if (k->key() == Qt::Key_Left) {
            ship->move_left();
        }

        if (k->key() == Qt::Key_Right) {
            ship->move_right();

        }
    }
};





class MouseStrategy : public InputStrategy {
public:
    MouseStrategy() { name = "mouse"; };
    ~MouseStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins)
    {
        QMouseEvent *k = (QMouseEvent *)event;
        if (k->button() == Qt::LeftButton) {
            bullets->push_back(ship->shoot());
            shipFiringSound->play();
        }
        if (k->x() < ship->get_x()) {
            ship->move_left();
        }

        if (k->x() > ship->get_x()) {
            ship->move_right();
        }
    }
};





class Input {

private:
    void switchState(InputStrategy* newState) {
        //change current state to invinc if not already
        if (prevState!=nullptr) delete prevState;
        prevState = currState;
        currState = newState;
    }
public:
    Input(InputStrategy* initState) : currState(initState) {};
    ~Input() { delete currState; if (prevState!=nullptr) delete prevState; };

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins)
    {
        currState->moveEvents(event, ship, bullets, shipFiringSound, ins);
    }

    void getDefault() {
        auto x = dynamic_cast<DefaultStrategy*>(currState);
        if (!x) {
            switchState(new DefaultStrategy());
        }
    }

    void getKeyboard() {
        auto x = dynamic_cast<KeyboardStrategy*>(currState);
        if (!x) {
            switchState(new KeyboardStrategy());
        }
    }


    void getMouse() {
        auto x = dynamic_cast<MouseStrategy*>(currState);
        if (!x) {
            switchState(new MouseStrategy());
        }
    }

    QString getName() {
        return currState->name;
    }


private:
    InputStrategy* currState;
    InputStrategy* prevState = nullptr;
};
}
#endif // CONTROLLERSTATE_H
