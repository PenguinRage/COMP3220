#ifndef SWARM_H
#define SWARM_H

#include "alien.h"
#include <vector>
#include "commandcentre.h"

namespace si {
    class Swarm : public Alien
    {
        std::vector<Alien> children;

    public:
        ~Swarm(){}
        void add(Alien& alien);
        int getSize() const;
        Alien* getAlien(int i);
        bool isHit(int x, int y, int width, int height);
        void addTrajectory(std::string s);
        void move();

    private:
        CommandCentre m_commandCentre;
        int m_speed = 10;
    };
}


#endif // SWARM_H
