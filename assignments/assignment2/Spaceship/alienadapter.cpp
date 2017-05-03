#include "alienadapter.h"

namespace si {
    AlienAdapter::AlienAdapter() : Defender() {}
    AlienAdapter::AlienAdapter(int xPos, int yPos, int id) :
        Defender(xPos, yPos), m_id(id) {}

}

