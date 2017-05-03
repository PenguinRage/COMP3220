#ifndef ALIENADAPTER_H
#define ALIENADAPTER_H


#include "gameelement.h"

// Class Adapter
namespace si {
    class AlienAdapter : public Alien, private GameElement
    {
    public:
        AlienAdapter();
        AlienAdapter(int xPos, int yPos, int id=1);
        virtual int getSwarmID(){ return m_id; }

    private:
        int m_id;

    };
}


#endif // ALIENADAPTER_H
