#include "star.h"

namespace si {

    /**
     * \brief: Creates a background star.
     * \param: starX, the x coordinate of the star
     * \param: starY, the y coordinate of the star
     */
    Star::Star(int starX, int starY)
        : GameElement(starX, starY)
    {}

    /**
     * \brief: Transparency getter
     */
    float Star::getOpacity() const
    {
        return m_opacity;
    }

    /**
     * \brief: Change in transparency getter
     */
    float Star::getOpacityDelta() const
    {
        return m_opacityDelta;
    }

    /**
     * \brief: Transparency setter
     */
    void Star::setOpacity(float opacity)
    {
        m_opacity = opacity;
    }

    /**
     * \brief: Change transparency direction to achieve twinkling effect
     */
    void Star::toggleOpacityDelta()
    {
        m_opacityDelta = -m_opacityDelta;
    }

} // end namespace si
