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
}
