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
}
