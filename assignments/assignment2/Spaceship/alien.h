#ifndef ALIEN_H
#define ALIEN_H

#include "gameelement.h"
#include "swarmcomponent.h"

namespace si {

class Alien : public GameElement
    {
    public:

        Alien(int x, int y, int id);
        void setSwarmID(int id);
        int getSwarmID();
        bool isAlive();


    private:
        int m_swarmID;
        bool m_alive = true;

    };
}


#endif // ALIEN_H
