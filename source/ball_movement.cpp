#include "../include/pong.hpp"

void ball_movement(Game &pong)
{
    if (pong.ball.position.x <= 12) {
        pong.player1.update(0);
        pong.player2.update(1);
        pong.ball.reset();
        play_goal_sound(pong);
    }
    if (pong.ball.position.x >= 1918) {
        pong.player1.update(1);
        pong.player2.update(0);
        pong.ball.reset();
        play_goal_sound(pong);
    }
    if (pong.ball.position.y <= 12 || pong.ball.position.y >= 1012) {
        pong.ball.going_top = !pong.ball.going_top;
        play_wall_sound(pong);
    }
    if ((pong.ball.position.x - pong.ball.x_speed <= pong.player1.racket.origin.x + 12) && (pong.ball.position.x - pong.ball.x_speed >= pong.player1.racket.origin.x)) {
        if (pong.ball.position.y <= pong.player1.racket.origin.y + 70 &&
            pong.ball.position.y >= pong.player1.racket.origin.y - 70) {
            pong.ball.going_left = !pong.ball.going_left;
            play_racket_sound(pong);
            }
    }
    if ((pong.ball.position.x + pong.ball.x_speed >= pong.player2.racket.origin.x - 12) && (pong.ball.position.x + pong.ball.x_speed <= pong.player2.racket.origin.x)) {
        if (pong.ball.position.y <= pong.player2.racket.origin.y + 70 &&
            pong.ball.position.y >= pong.player2.racket.origin.y - 70) {
            pong.ball.going_left = !pong.ball.going_left;
            play_racket_sound(pong);
            }
    }
    return ;
}