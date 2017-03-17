#include <iostream>

#include "bicycle.h"

using namespace transport;

int main(int argc, char* argv[]) {

    Bicycle bicycle1(1, 15);
    Bicycle bicycle2(1, 10, std::string("Blue"));
    Bicycle bicycle3(1, 15, true);
    Bicycle bicycle4(1, 10, std::string("Yellow"), true);
    Bicycle bicycle5(1, 15, true, 3);
    Bicycle bicycle6(1, 10, std::string("Green"), true, 3);

    std::cout << bicycle1.getSafetyRating() << std::endl;
    std::cout << bicycle2.getSafetyRating() << std::endl;
    std::cout << bicycle3.getSafetyRating() << std::endl;
    std::cout << bicycle4.getSafetyRating() << std::endl;
    std::cout << bicycle5.getSafetyRating() << std::endl;
    std::cout << bicycle6.getSafetyRating() << std::endl;

    return 0;
}
