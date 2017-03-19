#include "car.h"
#include "motorvehicle.h"


transport::Car::Car(int numberOfPassengers,
    int topSpeed,
    double kilometresPerLitre,
    int numberOfAirBags,
    bool abs,
    int numberOfWheels)
    : MotorVehicle(numberOfPassengers,topSpeed,numberOfWheels,kilometresPerLitre),
      m_abs(abs), m_numberOfAirBags(numberOfAirBags) {}

transport::Car::Car(int numberOfPassengers,
    int topSpeed,
    double kilometresPerLitre,
    std::string color,
    int numberOfAirBags,
    bool abs,
    int numberOfWheels)
    : MotorVehicle(numberOfPassengers,topSpeed,numberOfWheels,color,kilometresPerLitre),
      m_abs(abs), m_numberOfAirBags(numberOfAirBags) {}


int transport::Car::getSafetyRating() {
    int safetyRating = 0;
    if (m_numberOfAirBags >= 4) {
        safetyRating += 3;
    } else if (m_numberOfAirBags >= 2) {
        safetyRating += 2;
    } else if (m_numberOfAirBags > 0) {
        safetyRating += 1;
    }

    if (m_abs) {
        safetyRating += 2;
    }
    return safetyRating;
}
