#include "alien.h"

namespace si {
    Alien::Alien(int x, int y, int id) : GameElement(x,y), m_swarmID(id) {}

    void Alien::setSwarmID(int id){ m_swarmID = id;}

    int Alien::getSwarmID(){return m_swarmID;}

    bool Alien::isAlive(){return m_swarmID;}


}

