#include "bullet.h"

namespace si {

    /**
     * \brief: Instantiates a GameElement object
     * \param: bulletStartX, starting point for this bullet
     * \param: bulletStartY, starting point for this bullet
     */
    Bullet::Bullet(int bulletStartX, int bulletStartY)
        : GameElement(bulletStartX, bulletStartY)
    {}

    /**
     * \brief: Determines the amount of x direction motion of the bullet
     *         in each frame.
     * \param: updateAmount, the number of pixels to move in the x direction
     */
    void Bullet::updateX(int updateAmount)
    {
        // Nothing, unless we want diagonal trajectory bullets
    }

    /**
     * \brief: Determines the amount of y direction motion of the bullet
     *         in each frame.
     * \param: updateAmount, the number of pixels to move in the y direction
     */
    void Bullet::updateY(int updateAmount)
    {
        m_yPos -= updateAmount;
    }

} // end namespace si
