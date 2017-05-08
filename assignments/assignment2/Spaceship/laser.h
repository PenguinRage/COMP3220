#ifndef LASER_H
#define LASER_H

#include "bullet.h"

namespace si {
// Adapter for Laser
class Laser {
    public:
        virtual void updateX(int)=0;
        virtual void updateY(int)=0;
        virtual int PosX()=0;
        virtual int PosY()=0;

};


    class LaserAdapter : public Laser, public Bullet
    {
    public:
        LaserAdapter(int x, int y) : Bullet(x,y) {}
        ~LaserAdapter(){}

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

        /**
         * \brief: Determines the Position of Lasers
         * \return: returns the values assigned to class
         */
        int PosX() {return Bullet::getX();}
        int PosY() {return Bullet::getY();}

    private:
        int diagonal = 0;
    };
}

#endif // LASER_H
