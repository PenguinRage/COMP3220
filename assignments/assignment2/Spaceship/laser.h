#ifndef LASER_H
#define LASER_H

#include "bullet.h"

namespace si {
    class Laser : public Bullet
    {
    public:
        Laser(int x, int y) : Bullet(x,y) {}
        ~Laser(){}

        /**
         * \brief: Determines the amount of x direction motion of the bullet
         *         in each frame.
         * \param: updateAmount, the number of pixels to move in the x direction
         */
        void updateX(int updateAmount)
        {
            if (diagonal == 1)
            {
                m_xPos += updateAmount;
            }
            else if (diagonal == -1)
            {
                m_xPos -= updateAmount;
            }
        }

        /**
         * \brief: Determines the amount of y direction motion of the bullet
         *         in each frame.
         * \param: updateAmount, the number of pixels to move in the y direction
         */
        void updateY(int updateAmount)
        {
            m_yPos += updateAmount;
        }

    private:
        int diagonal = 0;
    };
}

#endif // LASER_H
