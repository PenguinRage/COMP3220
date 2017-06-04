#include "testingunit.h"

namespace game {
void TestingUnit::toUpper() {
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}
}
