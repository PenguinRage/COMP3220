#include "score.h"

namespace si {
    Score::Score(){}

    /**
     * \brief: gets score
     * \result: score count
     */
    int Score::getScore() const
    {
        return m_score;
    }

    /**
     * \brief: increments score
     */
    void Score::increment()
    {
        m_score++;
    }
}

