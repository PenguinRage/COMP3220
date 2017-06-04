#ifndef TESTINGUNIT_H
#define TESTINGUNIT_H

#include "config.h"
#include <QString>
#include <iostream>
#include <QSoundEffect>
#include "ship.h"
#include "controllerstrategy.h"


namespace game {
class TestingUnit
{
public:
    TestingUnit(){}
    ~TestingUnit(){}
    bool runTests();

private:
    int numberOfTestsFailed = 0;
    bool configCaseTest();
    bool shipCaseTest();
    bool alienCaseTest();
    bool strategyCaseTest();

};
}

#endif // TESTINGUNIT_H
