#include "swarm.h"

namespace si {

/**
 * \brief: adds to alien to the swarm of aliens
 * \param: Passes reference of Alien
 */
void Swarm::add(Alien& alien) {
    children.push_back(alien);
}


/**
 * \brief: gets size of swarm
 * \result: size of number of aliens
 */
int Swarm::getSize() const
{
    return children.size();
}



/**
 * \brief: gets alien in pos i
 * \param: i is the position in the vector of swarm aliens
 * \result: returns reference of the alien
 */
Alien* Swarm::getAlien(int i)
{
        return &children[i];
}


/**
 * \brief: checks if any aliens are hit by the incoming bullet
 * \param: pos of bullet x y, and the dimensions of the hit box
 * \result: true if hit because alien is now dead, false otherwise
 */
bool Swarm::isHit(int x, int y, int width, int height)
{
    for (auto &curAlien : children)
    {
        if (curAlien.isHit(x,y, width, height))
        {
            return true;
        }
    }
    return false;
}


/**
 * \brief: Adds alien trajectory to swarm in form of commandcentre
 * \param: command of direction to head in
 */
void Swarm::addTrajectory(std::string s) {
    m_commandCentre.addToBuffer(s);
}


/**
 * \brief: move all aliens in direction of trajectory
 */
void Swarm::move()
{
    if (m_commandCentre.hasNext()) {
        std::string nextCommand = m_commandCentre.popNext();
        if (nextCommand == "Left") {
            for (auto &curAlien : children)
            {
                curAlien.setX(curAlien.getX() - m_speed);
            }
        } else if (nextCommand == "Right") {
            for (auto &curAlien : children)
            {
                curAlien.setX(curAlien.getX() + m_speed);
            }
        } else if (nextCommand == "Up") {
            for (auto &curAlien : children)
            {
                curAlien.setY(curAlien.getY() - m_speed);
            }
        } else if (nextCommand == "Down") {
            for (auto &curAlien : children)
            {
                curAlien.setY(curAlien.getY() + m_speed);
            }
        }
        m_commandCentre.addToBuffer(nextCommand);
    }
}

}

