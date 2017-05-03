#include "alien.h"

namespace si {
    Alien::Alien(int x, int y, char id) : GameElement(x,y), m_swarmID(id) {}

    void Alien::setSwarmID(char id){ m_swarmID = id;}

    char Alien::getSwarmID(){return m_swarmID;}

    bool Alien::isAlive(){return m_swarmID;}

}

