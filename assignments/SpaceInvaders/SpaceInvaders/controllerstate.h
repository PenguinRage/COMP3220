#ifndef CONTROLLERSTATE_H
#define CONTROLLERSTATE_H

#include <iostream>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSound>
#include <vector>

#include "ship.h"

namespace game {

class ControllerState {
public:
    ControllerState() {};
    virtual ~ControllerState() {};

    virtual void keyEvent(QKeyEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound) = 0;
};




class KeyboardState : public ControllerState {
public:
    KeyboardState() {};
    ~KeyboardState() {};

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





class MouseState : public ControllerState {
public:
    MouseState() {};
    ~MouseState() {};

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





class Controller {

private:
    void switchState(ControllerState* newState) {
        //change current state to invinc if not already
        if (prevState!=nullptr) delete prevState;
        prevState = currState;
        currState = newState;
    }
public:
    Controller(ControllerState* initState) : currState(initState) {};
    ~Controller() { delete currState; };

    void keyEvent(QKeyEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound)
    {

        currState->keyEvent(event, ship, bullets, shipFiringSound);
    }


    void getKeyboard() {
        auto x = dynamic_cast<KeyboardState*>(currState);
        if (!x) {
            switchState(new KeyboardState());
        }
    }


    void getMouse() {
        auto x = dynamic_cast<MouseState*>(currState);
        if (!x) {
            switchState(new MouseState());
        }
    }


private:
    ControllerState* currState;
    ControllerState* prevState = nullptr;
};
}
#endif // CONTROLLERSTATE_H
