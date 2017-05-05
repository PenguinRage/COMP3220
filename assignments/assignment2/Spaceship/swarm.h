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
        bool isHit(int x, int y, int width, int height);
    };
}


#endif // SWARM_H
