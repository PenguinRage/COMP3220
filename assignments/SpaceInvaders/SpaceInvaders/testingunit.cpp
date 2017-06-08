#include "testingunit.h"



namespace game {

// Testing Unit for Config
bool TestingUnit::configCaseTest()
{
    int counter;
    Config* c = Config::getInstance();
    if (c->get_frames() == 80) counter++;
    QPair<QString, int> element = c->getScoreboard().at(0);
    if (element.second != 1115) counter++;
    return counter;
}

// Testing Unit for ship and it's new weapon
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

    Bullet* b = ship->shootBackup();
    b->setTarget(x);

    delete b;
    delete ship;
    return counter;
}

// Testing Unit for strategy behavioural design pattern
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

// Testing Unit for scoreboard
bool TestingUnit::scoreboardCaseTest() {
    int counter;
    Config* c = Config::getInstance();
    QList<QPair<QString, int>> scoreboard  = c->getScoreboard();
    QString test1 = "";
    int test2 = 1;

    for (int i = 0; i < scoreboard.size(); i++) {
        if (typeid(scoreboard.at(i).first) != typeid(test1)) counter++;
        if (typeid(scoreboard.at(i).second) != typeid(test2)) counter++;
    }
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
    if (!scoreboardCaseTest()) {
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
    return true;
}
}

