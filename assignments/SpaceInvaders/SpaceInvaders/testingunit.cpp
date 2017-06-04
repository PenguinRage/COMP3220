#include "testingunit.h"



namespace game {

bool TestingUnit::configCaseTest()
{
    int counter;
    Config* c = Config::getInstance();
    if (c->get_name() != "ian") counter=1;
    QPair<QString, int> element = c->getScoreboard().at(0);
    if (element.second != 1115) counter=1;
    return counter;
}

bool TestingUnit::shipCaseTest()
{
    int counter;
    Config* c = Config::getInstance();
    // SHIP
    QPixmap s;
    s.load(":/Images/ship.png");
    Ship * ship = new Ship(s, c->get_scale(), c->get_startpos(), 300);
    if (!ship->collides(100,100,100,100)) counter=1;
    int x = ship->get_x();
    ship->move_left();
    if (!ship->get_x() != x-15) counter=1;
    ship->move_right();
    if (!ship->get_x() != x) counter=1;
    delete ship;
    return counter;
}

bool TestingUnit::strategyCaseTest()
{
    int counter;
    Config* c = Config::getInstance();
    // Controller
    Input* remote = new Input(new DefaultStrategy());
    if (remote->getName() != "default") counter = 1;
    remote->getKeyboard();
    if (remote->getName() != "keyboard") counter = 1;
    remote->getMouse();
    if (remote->getName() != "mouse") counter = 1;
    remote->getDefault();
    if (remote->getName() != "default") counter = 1;

    delete remote;

    return counter;
}


bool TestingUnit::alienCaseTest()
{
    int counter;
    Config* c = Config::getInstance();
    // SHIP

    return counter;
}


bool TestingUnit::runTests() {
    if (!configCaseTest()) {
        numberOfTestsFailed++;
    }
    if (!shipCaseTest()) {
        numberOfTestsFailed++;
    }
    if (!strategyCaseTest()) {
        numberOfTestsFailed++;
    }
    if (0 == numberOfTestsFailed)
    {
        std::cout << "All Tests Passed!" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}
}

