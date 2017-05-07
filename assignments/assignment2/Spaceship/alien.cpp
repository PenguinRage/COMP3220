#include "alien.h"
#include <random>
namespace si {

    Alien::Alien(int x, int y, int id) : GameElement(x,y), m_swarmID(id) {}


    /**
     * \brief: sets the id of the swarm cluster
     * \param: takes an integer
     */
    void Alien::setSwarmID(int id){ m_swarmID = id;}

    /**
     * \brief: gets the id of the swarm cluster
     * \result: alien id
     */
    int Alien::getSwarmID(){return m_swarmID;}

    /**
     * \brief: checks if Alien is still alive
     * \result: true if alive otherwise dead
     */
    bool Alien::isAlive(){return m_alive;}

    /**
     * \brief: checks if Alien is still Hit
     * \param: if bullet x y is in hit box it is hit
     * \result: false if hit because alien is now dead, true otherwise
     */
    bool Alien::isHit(int x, int y, int width, int height)
    {
        if (x > getX() && x < (getX() + width) && y > getY() && y < (getY() + height))
        {
            m_alive = false;
            return true;
        }

        return false;
    }


    /**
     * \brief: sets alien to blow up
     * \param: set alien to explode
     */
    void Alien::setDestroyed(bool value)
    {
        m_destroyed = value;
    }

    /**
     * \brief: checks to see if ship is blown up
     * \result: false if alive/dead for more then 1 frame, true otherwise
     */
    bool Alien::isBlown()
    {
        return m_destroyed;
    }

    /**
     * \brief: checks if Alien should peroidically shoot
     * \result: true if aliens turn to shoot now, otherwise false
     */
    bool Alien::shoot()
    {
        if ((rand() % 100000) > 99500)
        {
            return true;
        }

        return false;
    }
}

