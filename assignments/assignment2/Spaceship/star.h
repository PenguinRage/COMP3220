#ifndef STAR_H
#define STAR_H

#include "gameelement.h"

namespace si {

    class Star : public GameElement
    {
    public:
        Star(int starX, int starY);

        float getOpacity() const;
        float getOpacityDelta() const;

        void setOpacity(float opacity);
        void toggleOpacityDelta();

    private:
        float m_opacity = 0.0f;
        float m_opacityDelta = 0.01f;
    };

} // end namespace si

#endif // STAR_H
