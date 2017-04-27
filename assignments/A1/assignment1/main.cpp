#include "battlesphere.h"
#include <QApplication>

using namespace si;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    BattleSphere w;

    w.show();

    a.exec();

    return 0;
}
