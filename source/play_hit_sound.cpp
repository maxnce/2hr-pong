#include "../include/pong.hpp"

int play_racket_sound(Game &pong)
{   
    pong.sounds.racket.setPlayingOffset(sf::Time::Zero);
    pong.sounds.racket.play();
    return 0;
}

int play_wall_sound(Game &pong)
{   
    pong.sounds.wall.setPlayingOffset(sf::Time::Zero);
    pong.sounds.wall.play();
    return 0;
}

int play_goal_sound(Game &pong)
{   
    pong.sounds.goal.setPlayingOffset(sf::Time::Zero);
    pong.sounds.goal.play();
    return 0;
}