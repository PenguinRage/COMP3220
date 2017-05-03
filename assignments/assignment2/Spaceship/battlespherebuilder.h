#ifndef BATTLESPHEREBUILDER_H
#define BATTLESPHEREBUILDER_H

#include <string>

#include "battlesphere.h"
#include "defender.h"
#include "commandcentre.h"
#include "swarmcomposite.h"

namespace si {

    class BattlesphereBuilder
    {
    public:
        BattlesphereBuilder(){}

        void buildDefender(const Defender &d);

        void buildBulletParameters(int movementSpeed);

        void buildCommandCentre(const CommandCentre& commandCentre);

        void buildSwarm(const std::vector<SwarmComposite>& swarm);

        si::BattleSphere* getBattlesphere();

    private:
        Defender m_defender;
        int m_bulletSpeed;
        CommandCentre m_commandCentre;
        std::vector<SwarmComposite> m_swarm;
    };

} // end namespace si

#endif // BATTLESPHEREBUILDER_H
