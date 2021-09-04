#include "../include/pong.hpp"

void game_loop(Game &pong, sf::Event event)
{
    // Close window: on close or on escape pressed.
    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        pong.window.close();
        return ;
    }
    switch (event.type) {
    case sf::Event::KeyPressed: handle_key_pressed(pong, event);
    break;
    case sf::Event::KeyReleased: handle_key_released(pong, event);
    break;
    default: return;
    }
}