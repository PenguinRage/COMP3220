#ifndef ALIEN_H
#define ALIEN_H

#include "gameelement.h"
#include "swarmcomponent.h"

namespace si {

class Alien : public GameElement, public SwarmComponent
    {
    public:

        Alien(int x, int y, char id);
        void setSwarmID(char id);
        char getSwarmID();
        bool isAlive();


    private:
        char m_swarmID;
        bool m_alive = true;

    };
}


#endif // ALIEN_H
