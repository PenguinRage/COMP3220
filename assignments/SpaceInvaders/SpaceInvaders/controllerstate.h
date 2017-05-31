#ifndef CONTROLLERSTATE_H
#define CONTROLLERSTATE_H

#include <iostream>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSound>
#include <vector>

#include "ship.h"

namespace game {

class ControllerStrategy {
public:
    ControllerStrategy() {};
    virtual ~ControllerStrategy() {};

    virtual void keyEvent(QKeyEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound) {return; }
    virtual void mouseEvent(QMouseEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound) { return; }
};




class KeyboardStrategy : public ControllerStrategy {
public:
    KeyboardStrategy() {};
    ~KeyboardStrategy() {};

    virtual void keyEvent(QKeyEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound)
    {
        if (event->key() == Qt::Key_Space) {
            bullets->push_back(ship->shoot());
            shipFiringSound->play();
        }

        if (event->key() == Qt::Key_Left) {
            ship->move_left();
        }

        if (event->key() == Qt::Key_Right) {
            ship->move_right();

        }
    }
};





class MouseStrategy : public ControllerStrategy {
public:
    MouseStrategy() {};
    ~MouseStrategy() {};

    virtual void mouseEvent(QMouseEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound)
    {
        if (event->x() < ship->get_x()) {
            ship->move_left();
        }

        if (event->x() > ship->get_x()) {
            ship->move_right();
        }
    }
};





class Controller {

private:
    void switchState(ControllerStrategy* newState) {
        //change current state to invinc if not already
        if (prevState!=nullptr) delete prevState;
        prevState = currState;
        currState = newState;
    }
public:
    Controller(ControllerStrategy* initState) : currState(initState) {};
    ~Controller() { delete currState; };

    virtual void keyEvent(QKeyEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound)
    {

        currState->keyEvent(event, ship, bullets, shipFiringSound);
    }

    virtual void keyEvent(QMouseEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound)
    {

        currState->mouseEvent(event, ship, bullets, shipFiringSound);
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


private:
    ControllerStrategy* currState;
    ControllerStrategy* prevState = nullptr;
};
}
#endif // CONTROLLERSTATE_H
