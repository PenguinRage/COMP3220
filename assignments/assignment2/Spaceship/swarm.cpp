#include "swarm.h"

namespace si {
Swarm::Swarm() {}

void Swarm::add(Alien& alien) {
    children.push_back(alien);
}

int Swarm::getSize() const
{
    return children.size();
}

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

void Swarm::addTrajectory(std::string s) {
    m_commandCentre.addToBuffer(s);
}

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
        }
        m_commandCentre.addToBuffer(nextCommand);
    }
}

}

