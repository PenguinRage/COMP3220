#ifndef SWARMCOMPOSITE_H
#define SWARMCOMPOSITE_H

#include "alien.h"
#include <vector>

namespace si {

    class SwarmComposite : public SwarmComponent
    {
        std::vector < SwarmComponent * > children;
    public:
        void add(SwarmComponent * ele);
        void move();
    };
}

#endif // SWARMCOMPOSITE_H
