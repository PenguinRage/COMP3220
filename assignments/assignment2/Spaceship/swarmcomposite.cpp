#include "swarmcomposite.h"

namespace si {
    void SwarmComposite::add(SwarmComponent *ele)
    {
        children.push_back(ele);
    }

    void SwarmComposite::move()
    {
        //
    }
}
