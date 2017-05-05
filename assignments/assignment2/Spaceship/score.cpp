#include "score.h"

namespace si {
    Score::Score(){}

    int Score::getScore() const
    {
        return m_score;
    }

    void Score::increment()
    {
        m_score++;
    }
}

