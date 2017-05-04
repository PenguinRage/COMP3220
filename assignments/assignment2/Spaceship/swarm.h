#ifndef SWARM_H
#define SWARM_H

#include "alien.h"
#include <vector>
namespace si {
    class Swarm
    {
    public:
        Swarm();
        std::vector<Alien> children;
        void add(Alien& alien);
        int getSize() const;

    };
}


#endif // SWARM_H
