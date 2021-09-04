#include "../include/pong.hpp"

void ball_movement(Game &pong)
{
    if (pong.ball.position.x <= 0 || pong.ball.position.x >= 1920) {
        pong.ball.going_left = !pong.ball.going_left;
    }
    if (pong.ball.position.y <= 0 || pong.ball.position.y >= 1080) {
        pong.ball.going_top = !pong.ball.going_top;
    }
    return ;
}