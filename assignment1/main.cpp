#include "battlesphere.h"
#include <QApplication>
#include "config.h"
#include "spaceitemfactory.h"

using namespace si;
Config * config;

// Easy way to setup on Windows || Linux
string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";

// Validation for Integers returns false to throw error
bool validateInt(const string input) {
    // The number of negative signs in string
    int negative_count =count(input.begin(), input.end(), '-');
    // if only '-'
    if((signed int) input.size() == negative_count) return false;
    // if '---1'
    else if (negative_count > 1) return false;
    //if negative sign is in wrong place
    else if (negative_count == 1 && input[0] != '-') return false;
    // The string contains a character that isn't within "-0123456789"
    else if (strspn(input.c_str(), "-0123456789") != input.size()) return false;
    return true;
}

int getNumber(string key) {
    string value = config->get_value(key);

    if (validateInt(value)) {
        return (int) strtod(value.c_str(), NULL);
    } else throw "The value for key: \"" + key + "\" should be a number. ";
}

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
    // Config Load data from config
    config->load();

    // Use of Factory Method
    ship = (SpaceShip *) factory.make(SPACESHIP,getNumber("defenderx"),getNumber("defendery"),getNumber("defenders"));
    w.setDefender(ship->getDefender());

    w.show();

    a.exec();
    delete ship;
    config->destroy();
    return 0;
}
