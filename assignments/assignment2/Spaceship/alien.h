#ifndef ALIEN_H
#define ALIEN_H

#include "gameelement.h"

namespace si {

class Alien : public GameElement
    {
    public:

        Alien(int x, int y, int id);
        void setSwarmID(int id);
        int getSwarmID();
        bool isAlive();
        bool isBlown();
        void setDestroyed(bool value);
        bool isHit(int x, int y, int width, int height);


    private:
        int m_swarmID;
        bool m_alive = true;
        bool m_destroyed = false;

    };
}


#endif // ALIEN_H
