#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>

const float SCREEN_WIDTH = 1920;
const float SCREEN_HEIGHT = 1080;

class Coordinates {
    public:
        float x;
        float y;

        Coordinates(float default_x = SCREEN_WIDTH / 2, float default_y = SCREEN_HEIGHT / 2) {
            x = default_x;
            y = default_y;
        }

        void set_to_middle_screen() {
            x = SCREEN_WIDTH / 2;
            y = SCREEN_HEIGHT / 2;
        }

        void set_to_zero() {
            x = 0;
            y = 0;
        }
};

class Ball {
    public:
        Coordinates position;
        Coordinates speed;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale;

        void reset() {
            position.set_to_middle_screen();
            speed.set_to_zero();
        }

        Ball() {
            if (!texture.loadFromFile("assets/ball.png"))
                exit(EXIT_FAILURE);
            sprite.setTexture(texture, false);
            sf::Vector2f temp_pos{position.x, position.y};
            sprite.setPosition(temp_pos);
        }
};

class Racket {
    public:
        Coordinates origin;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale;
        void initialize_by_player_number(int player_number) {
            set_coordinates_by_player_number(player_number);
            if (!texture.loadFromFile("assets/ball.png"))
                exit(EXIT_FAILURE);
            sprite.setTexture(texture, false);
            sf::Vector2f temp_pos{origin.x, origin.y};
            sprite.setPosition(temp_pos);
        }
        void set_coordinates_by_player_number(int player_number) {
            if (player_number == 1)
                origin.x = 20;
            else
                origin.x = 1900;
        }
};

class Player {
    public:
        int score {0};
        Racket racket;

        void initialize(int player_number) {
            if (player_number == 1 || player_number == 2)
                    racket.initialize_by_player_number(player_number);
            else {
                std::cout << "Internal error occured. Exiting." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
};

class Game {
    public:
        sf::RenderWindow window;
        Player player1;
        Player player2;
        Ball ball;
        Game () {
            window.create(sf::VideoMode(1920, 1080), "Ponggo");
            player1.initialize(1);
            player2.initialize(2);
        }
};

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp("-h", av[1])) {
        std::cout << "use ./pong" << std::endl;
        return 0;
    }

    // Start game setup
    Game pong;

    // Load music
    /* sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE; */

    // Play the music
    /* music.play(); */

    // Start the game loop
    while (pong.window.isOpen())
    {
        // Process events
        sf::Event event;
        while (pong.window.pollEvent(event))
        {
            // Close window: on close or on escape pressed.
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                pong.window.close();
        }
        // Clear screen
        pong.window.clear();
        // Draw the sprites
        pong.window.draw(pong.ball.sprite);
        pong.window.draw(pong.player1.racket.sprite);
        pong.window.draw(pong.player2.racket.sprite);

        // Update the window
        pong.window.display();
    }
    return 0;
}
  