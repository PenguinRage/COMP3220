#ifndef CAR_H
#define CAR_H

#include "motorvehicle.h"

namespace transport {
class Car : public MotorVehicle {
public:
    Car(int numberOfPassengers,
        int topSpeed,
        double kilometresPerLitre,
        int numberOfAirBags = 2,
        bool abs = true,
        int numberOfWheels = 4);

    Car(int numberOfPassengers,
        int topSpeed,
        double kilometresPerLitre,
        std::string color,
        int numberOfAirBags = 2,
        bool abs = true,
        int numberOfWheels = 4);

    virtual int getSafetyRating();

protected:
    int m_numberOfAirBags;
    bool m_abs;

};
}

#endif // CAR_H
