#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"
#include <string>

namespace transport {
class Bicycle : public Vehicle {
public:
    Bicycle(int numberOfPassengers,
        int topSpeed,
        bool helmetUsed = false,
        int numberOfWheels = 2)
        : Vehicle(numberOfPassengers,topSpeed,numberOfWheels) {
        m_helmetUsed = helmetUsed;
    }

    Bicycle(int numberOfPassengers,
        int topSpeed,
        std::string color,
        bool helmetUsed = false,
        int numberOfWheels = 2)
        : Vehicle(numberOfPassengers,topSpeed,numberOfWheels,color)
    {
        m_helmetUsed = helmetUsed;
    }

    int getSafetyRating() {
        if (m_helmetUsed) {
            return 5;
        } else {
            return 0;
        }
    }

protected:
    bool m_helmetUsed;
};
}

#endif // BICYCLE_H
