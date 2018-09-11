#ifndef PLAYER_H
#define PLAYER_H

#include <QtGlobal>

enum class BallColor{
    YELLOW,
    RED
};

class Player
{
private:
    const BallColor m_myBall;
    qint32 m_score;


public:
    Player(BallColor myball);
    void incrementScore();
    void decrementScore();
};

#endif // PLAYER_H
