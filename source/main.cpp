#include "../include/pong.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp("-h", av[1])) {
        std::cout << "use ./pong" << std::endl;
        return 0;
    }

    // Start game setup
    Game pong;

    // Load music

    // Play the music
    /* music.play(); */

    // Start the game loop
    while (pong.window.isOpen())
    {
        // Process events
        sf::Event event;
        while (pong.window.pollEvent(event))
        {
            game_loop(pong, event);
        }
        // Clear screen
        ball_movement(pong);
        pong.window.clear();
        // Draw the sprites
        pong.player1.update();
        pong.player2.update();
        pong.ball.update();
        pong.window.draw(pong.ball.sprite);
        pong.window.draw(pong.player1.racket.sprite);
        pong.window.draw(pong.player2.racket.sprite);
        pong.window.draw(pong.player1.score);
        pong.window.draw(pong.player2.score);

        // Update the window
        pong.window.display();
    }
    return 0;
}
  