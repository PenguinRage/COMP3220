#ifndef DEFENDER_H
#define DEFENDER_H

#include <string>

#include "gameelement.h"

namespace si {

    class Defender : public GameElement
    {
    public:
        Defender(int xPos, int yPos, std::string m_scale, int speed);
        Defender();
        ~Defender(){}

        std::string getScale() const;
        int getSpeed() const;

        void setScale(std::string scale);
        void setSpeed(int speed);

    private:
        std::string m_scale;
        int m_speed = 10;
    };

} // end namespace si

#endif // DEFENDER_H
