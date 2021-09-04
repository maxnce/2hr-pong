#include "../include/pong.hpp"

void handle_key_pressed(Game &pong, sf::Event event)
{
    switch (event.key.code) {
        case sf::Keyboard::A: pong.player1.racket.up = true;
        break;
        case sf::Keyboard::Q: pong.player1.racket.down = true;
        break;
        case sf::Keyboard::Up: pong.player2.racket.up = true;
        break;
        case sf::Keyboard::Down: pong.player2.racket.down = true;
        break;
        default: return;
    }
}

void handle_key_released(Game &pong, sf::Event event)
{
    switch (event.key.code) {
        case sf::Keyboard::A: pong.player1.racket.up = false;
        break;
        case sf::Keyboard::Q: pong.player1.racket.down = false;
        break;
        case sf::Keyboard::Up: pong.player2.racket.up = false;
        break;
        case sf::Keyboard::Down: pong.player2.racket.down = false;
        break;
        default: return;
    }
}