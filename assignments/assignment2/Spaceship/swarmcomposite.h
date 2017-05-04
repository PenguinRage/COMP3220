#ifndef SWARMCOMPOSITE_H
#define SWARMCOMPOSITE_H

#include "alien.h"
#include <vector>

namespace si {

    class SwarmComposite : public Alien
    {
    public:
        void add(Alien * ele);
        std::vector < Alien * > children;
        void move();
    };
}

#endif // SWARMCOMPOSITE_H
