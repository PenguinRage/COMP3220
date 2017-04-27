#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

namespace transport {
    class Vehicle {
    public:
        Vehicle(int numberOfPassengers,
            int topSpeed,
            int numberOfWheels,
            std::string color = "red") {
            m_numberOfPassengers = numberOfPassengers;
            m_topSpeed = topSpeed;
            m_numberOfWheels = numberOfWheels;
            m_color = color;
        }

        ~Vehicle() {}

        std::string getColor() { return m_color; }

        int getTopSpeed() { return m_topSpeed; }

        int getNumberOfWheels() { return m_numberOfWheels; }

        int getNumberOfPassengers() {return m_numberOfPassengers; }

        virtual int getSafetyRating() = 0;

    protected:
        int m_numberOfPassengers;
        int m_topSpeed;
        int m_numberOfWheels;
        std::string m_color;
    };
}

#endif // VEHICLE_H
