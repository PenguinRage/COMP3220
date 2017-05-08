#ifndef ALIEN_H
#define ALIEN_H

#include "gameelement.h"
#include "component.h"

namespace si {

class Alien : public GameElement
    {
    public:
        Alien(int x=0, int y=0, int id=-1);
        void setSwarmID(int id);
        int getSwarmID();
        bool isAlive();
        bool isBlown();
        void setDestroyed(bool value);
        bool isHit(int x, int y, int width, int height);
        bool shoot();


    private:
        int m_swarmID;
        bool m_alive = true;
        bool m_destroyed = false;

    };
}


#endif // ALIEN_H
