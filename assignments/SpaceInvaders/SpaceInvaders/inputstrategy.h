#ifndef INPUTSTRATEGY_H
#define INPUTSTRATEGY_H

#include <iostream>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSound>
#include <vector>

#include "ship.h"

namespace game {

// Interface for the Strategy
class InputStrategy {
public:
    InputStrategy() {};
    virtual ~InputStrategy() {};
    QString name;

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins, int x)=0;
};


// Default Strategy for Basic
class DefaultStrategy : public InputStrategy {
public:
    DefaultStrategy() { name = "default"; };
    ~DefaultStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins, int x)
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


// Adds keyboard Strategy functionality
class KeyboardStrategy : public InputStrategy {
public:
    KeyboardStrategy() { name = "keyboard"; };
    ~KeyboardStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins, int x)
    {
        QKeyEvent *k = (QKeyEvent *)event;
        if (k->key() == Qt::Key_X) {
            ship->move_speed_left();
        }
        if (k->key() == Qt::Key_C) {
            ship->move_speed_right();
        }
        if (k->key() == Qt::Key_B) {
            Bullet* b = ship->shootBackup();
            b->setTarget(x);
            bullets->push_back(b);
            shipFiringSound->play();
        }
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


// Mouse Strategy Functionality
class MouseStrategy : public InputStrategy {
public:
    MouseStrategy() { name = "mouse"; };
    ~MouseStrategy() {};

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins, int x)
    {
        QMouseEvent *k = (QMouseEvent *)event;
        if (k->button() == Qt::LeftButton) {
            bullets->push_back(ship->shoot());
            shipFiringSound->play();
        }
        if (k->button() == Qt::RightButton) {
            Bullet* b = ship->shootBackup();
            b->setTarget(x);
            bullets->push_back(b);
            shipFiringSound->play();
        }
        if (k->x() < ship->get_x()) {
            if (k->button() == Qt::MidButton)
            {
                ship->move_speed_left();
            }
            else
                ship->move_left();
        }

        if (k->x() > ship->get_x()) {
            if (k->button() == Qt::MidButton)
            {
                ship->move_speed_right();
            }
            else
                ship->move_right();
        }
    }
};


// Input Strategy Class
class Input {

private:
    // Switches the state of the strategy
    void switchState(InputStrategy* newState) {
        //change current state to invinc if not already
        if (prevState!=nullptr) delete prevState;
        prevState = currState;
        currState = newState;
    }
public:
    Input(InputStrategy* initState) : currState(initState) {};
    ~Input() { delete currState; if (prevState!=nullptr) delete prevState; };

    virtual void moveEvents(QEvent* event, Ship* ship, std::vector<Bullet*>* bullets, QSoundEffect* shipFiringSound, QString ins, int x)
    {
        currState->moveEvents(event, ship, bullets, shipFiringSound, ins, x);
    }
    // Retrieves Default Strategy
    void getDefault() {
        auto x = dynamic_cast<DefaultStrategy*>(currState);
        if (!x) {
            switchState(new DefaultStrategy());
        }
    }
    // Retrieves Keyboard Strategy
    void getKeyboard() {
        auto x = dynamic_cast<KeyboardStrategy*>(currState);
        if (!x) {
            switchState(new KeyboardStrategy());
        }
    }
    // Retrieves Mouse Strategy
    void getMouse() {
        auto x = dynamic_cast<MouseStrategy*>(currState);
        if (!x) {
            switchState(new MouseStrategy());
        }
    }
    // Gets name of Strategy
    QString getName() {
        return currState->name;
    }

private:
    InputStrategy* currState;
    InputStrategy* prevState = nullptr;
};
}
#endif // CONTROLLERSTATE_H
