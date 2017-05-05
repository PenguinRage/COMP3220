#ifndef SCORE_H
#define SCORE_H

namespace si {
    class Score
    {
    public:
        Score();
        int getScore() const;
        void increment();

    private:
        int m_score = 0;
    };
}


#endif // SCORE_H
