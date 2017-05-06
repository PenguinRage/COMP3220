#include "alien.h"
#include <random>
namespace si {
    Alien::Alien(int x, int y, int id) : GameElement(x,y), m_swarmID(id) {}

    void Alien::setSwarmID(int id){ m_swarmID = id;}

    int Alien::getSwarmID(){return m_swarmID;}

    bool Alien::isAlive(){return m_alive;}

    bool Alien::isHit(int x, int y, int width, int height)
    {
        if (x > getX() && x < (getX() + width) && y > getY() && y < (getY() + height))
        {
            m_alive = false;
            return true;
        }

        return false;
    }

    void Alien::setDestroyed(bool value)
    {
        m_destroyed = value;
    }

    bool Alien::isBlown()
    {
        return m_destroyed;
    }

    bool Alien::shoot()
    {
        if ((rand() % 10000) > 9900)
        {
            return true;
        }

        return false;
    }
}

