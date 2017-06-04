#ifndef TESTINGUNIT_H
#define TESTINGUNIT_H


#include <QtTest/QtTest>
namespace game {
class TestingUnit
{
public:
    TestingUnit(){}
    ~TestingUnit(){}

    Q_OBJECT
public slots:
    void toUpper();
};

}

QTEST_MAIN(TestingUnit)
#include "testingunit.moc"

#endif // TESTINGUNIT_H
