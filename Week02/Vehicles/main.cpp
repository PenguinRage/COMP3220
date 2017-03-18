#include <iostream>

#include "bicycle.h"

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

    return 0;
}
