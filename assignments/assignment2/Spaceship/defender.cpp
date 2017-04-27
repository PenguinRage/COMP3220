#include "defender.h"

namespace si {

    /**
     * \brief: Constructs a new player (Defender) object
     * \param: xPos, starting x coordinate of player
     * \param: yPos, starying y coordinate of player
     * \param: scale, size of the player ("tiny", "normal", "large", "giant")
     */
    Defender::Defender(int xPos, int yPos, std::string scale, int speed)
        : GameElement(xPos, yPos),
          m_scale(scale),
          m_speed(speed)
    {}

    /**
     * \brief: Default defender constructor
     */
    Defender::Defender()
        : GameElement(0, 0),
          m_scale("tiny"),
          m_speed(10)
    {}

    /**
     * \brief: Sets the size of the player
     * \param: scale, size of the player ("tiny", "normal", "large", "giant")
     */
    void Defender::setScale(std::string scale)
    {
        m_scale = scale;
    }

    /**
     * \brief: Updates player movement
     * \param: speed, number of pixels traversed by player in each move
     */
    void Defender::setSpeed(int speed)
    {
        m_speed = speed;
    }

    /**
     * \brief: Getter function for scale
     * \result: the scale, one of ("tiny", "normal", "large", "giant")
     */
    std::string Defender::getScale() const
    {
        return m_scale;
    }

    /**
     * \brief: Getter function for speed
     * \result: speed, the number of pixels traversed by the player in each frame
     */
    int Defender::getSpeed() const
    {
        return m_speed;
    }

} // end namespace si
