#include <iostream>

#include "bicycle.h"
#include "bus.h"
#include "car.h"

using namespace transport;
using namespace std;

int main(int argc, char* argv[]) {

    Bicycle bicycle1(1, 15);
    Bicycle bicycle2(1, 10, string("Blue"));
    Bicycle bicycle3(1, 15, true);
    Bicycle bicycle4(1, 10, string("Yellow"), true);
    Bicycle bicycle5(1, 15, true, 3);
    Bicycle bicycle6(1, 10, string("Green"), true, 3);

    cout << bicycle1.getSafetyRating() << endl;
    cout << bicycle2.getSafetyRating() << endl;
    cout << bicycle3.getSafetyRating() << endl;
    cout << bicycle4.getSafetyRating() << endl;
    cout << bicycle5.getSafetyRating() << endl;
    cout << bicycle6.getSafetyRating() << endl;

    Bus bus1(1, 75, 10, true, false);
    Bus bus2(1, 75, 10, string("Blue"), true, true);
    Bus bus3(1, 75, 10);
    Bus bus4(1, 75, 10, false, true);

    cout << bus1.getSafetyRating() << endl;
    cout << bus2.getSafetyRating() << endl;
    cout << bus3.getSafetyRating() << endl;
    cout << bus4.getSafetyRating() << endl;

    Car car1(1, 75, 10, 4);
    Car car2(1, 75, 10, string("Blue"));
    Car car3(1, 75, 10);
    Car car4(1, 75, 10, 6, true, 4);
    Car car5(1, 75, 10, string("Green"), 6, true, 4);

    cout << car1.getSafetyRating() << endl;
    cout << car2.getSafetyRating() << endl;
    cout << car3.getSafetyRating() << endl;
    cout << car4.getSafetyRating() << endl;
    cout << car5.getSafetyRating() << endl;


    return 0;
}
