#include "battlesphere.h"
#include <QApplication>
#include "config.h"
#include "spaceitemfactory.h"

using namespace si;
Config * config;

// Easy way to setup on Windows || Linux
string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    BattleSphere w;
    SpaceItemFactory factory;
    SpaceShip * ship;
    // Create Config instance
    config = Config::get_instance();
    // Config PATH directory to global variable filename
    config->set_absolute_path(CONFIG_PATH);
    //Config Load data from config
    config->load();

    // Use of Factory Method
    ship = (SpaceShip *) factory.make(SPACESHIP,config->getNumber("defenderx"),config->getNumber("defendery"),config->getNumber("defenders"));
    w.setDefender(ship);
    w.show();

    a.exec();
    config->destroy();
    return 0;
}
