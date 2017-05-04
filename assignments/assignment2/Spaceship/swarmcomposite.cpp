#include "swarmcomposite.h"

namespace si {
    void SwarmComposite::add(Alien *ele)
    {
        children.push_back(ele);
    }

    void SwarmComposite::move()
    {
        //
    }
}
