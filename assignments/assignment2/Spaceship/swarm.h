#ifndef SWARM_H
#define SWARM_H

#include "alien.h"
#include <vector>
#include "commandcentre.h"

namespace si {
    class Swarm
    {
    public:
        Swarm();
        ~Swarm(){}
        std::vector<Alien> children;
        void add(Alien& alien);
        int getSize() const;
        bool isHit(int x, int y, int width, int height);
        void addTrajectory(std::string s);
        void move();

    private:
        CommandCentre m_commandCentre;
        int m_speed = 20;
    };
}


#endif // SWARM_H
