#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H

#include "battlesphere.h"
#include "battlespherebuilder.h"

namespace si {

    class GameDirector
    {
    public:
        si::BattleSphere* createBattleSphereStandardMode(BattlesphereBuilder& builder);
    };

} // end namespace si

#endif // GAMEDIRECTOR_H
