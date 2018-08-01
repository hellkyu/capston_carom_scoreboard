#include "player.h"


Player::Player(BallColor myball) : m_myBall(myball)
{
    m_score = 0;
}

void Player::incrementScore()
{
    m_score++;
}

void Player::decrementScore()
{
    if(m_score > 0){
        m_score--;
    }
}
