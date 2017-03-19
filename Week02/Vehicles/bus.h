#ifndef BUS_H
#define BUS_H

#include "motorvehicle.h"

namespace transport {

class Bus : public MotorVehicle
{
public:
    Bus(int numberOfPassengers,
        int topSpeed,
        double kilometresPerLitre,
        bool seatBeltsInstalled = false,
        bool standingPassengersAllowed = true,
        int numberOfWheels = 6)
        : MotorVehicle(numberOfPassengers,topSpeed,numberOfWheels,kilometresPerLitre),
          m_seatBeltsInstalled(seatBeltsInstalled),
          m_standingPassengersAllowed(standingPassengersAllowed) {}

    Bus(int numberOfPassengers,
        int topSpeed,
        double kilometresPerLitre,
        std::string color,
        bool seatBeltsInstalled = false,
        bool standingPassengersAllowed = true,
        int numberOfWheels = 6)
        : MotorVehicle(numberOfPassengers,topSpeed,numberOfWheels, color, kilometresPerLitre),
          m_seatBeltsInstalled(seatBeltsInstalled),
          m_standingPassengersAllowed(standingPassengersAllowed) {}

    virtual int getSafetyRating();


protected:
    bool m_seatBeltsInstalled;
    bool m_standingPassengersAllowed;
};
}

#endif // BUS_H
