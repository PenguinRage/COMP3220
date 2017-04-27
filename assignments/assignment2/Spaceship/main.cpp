#include "battlesphere.h"
#include "iofile.h"
#include "defender.h"
#include <QApplication>

#include "commandcentre.h"
#include "battlespherebuilder.h"
#include "gamedirector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    si::BattlesphereBuilder builder;
    si::GameDirector engine;

    si::BattleSphere* w = engine.createBattleSphereStandardMode(builder);

    w->show();
    a.exec();

    delete w;
    return 0;
}
