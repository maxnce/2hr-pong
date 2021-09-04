#ifndef PONG_HPP_
#define PONG_HPP_

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

class Sounds {
    public:
        sf::Music background;
        sf::Music ball_hit;
        sf::Music score;
        Sounds() {
            if (!background.openFromFile("assets/background.ogg"))
                exit(EXIT_FAILURE);
            background.play();
            background.setLoop(true);
            background.setVolume(40);
            /* if (!ball_hit.openFromFile("ball_hit.ogg"))
                exit(EXIT_FAILURE);
            if (!score.openFromFile("ball_hit.ogg"))
                exit(EXIT_FAILURE); */
        }
};

class Ball {
    public:
        Coordinates position;
        int x_speed {0};
        int y_speed {0};
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale {0.75, 0.75};
        bool going_left {false};
        bool going_top {false};

        void reset() {
            position.set_to_middle_screen();
            set_random_movement();
        }

        void set_random_movement(void) {
            srand(time(NULL));
            going_left = rand() % 2;
            going_top = rand() % 2;
            y_speed = rand() % 5;
            x_speed = 10 - y_speed;
        }

        void update(void) {
            position.x += (going_left ? x_speed * -1 : x_speed);
            position.y += (going_top ? y_speed * -1 : y_speed);
            sf::Vector2f temp_pos {position.x + (going_left ? x_speed * -1 : x_speed), position.y + (going_top ? y_speed * -1 : y_speed)};
            sprite.setPosition(temp_pos);
        }

        Ball() {
            if (!texture.loadFromFile("assets/ball.png"))
                exit(EXIT_FAILURE);
            sprite.setTexture(texture, false);
            sf::Vector2f temp_origin{12, 12};
            sprite.setOrigin(temp_origin);
            sprite.setScale(scale);
            sf::Vector2f temp_pos{position.x, position.y};
            sprite.setPosition(temp_pos);
            set_random_movement();
        }
};

class Racket {
    public:
        Coordinates origin;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale {0.5, 0.5};
        int speed {0};
        bool up {false};
        bool down {false};

        void initialize_by_player_number(int player_number) {
            set_coordinates_by_player_number(player_number);
            if (!texture.loadFromFile("assets/racket.png"))
                exit(EXIT_FAILURE);
            sprite.setTexture(texture, false);
            sf::Vector2f temp_origin{18, 135};
            sprite.setScale(scale);

            sprite.setOrigin(temp_origin);
            sf::Vector2f temp_pos{origin.x, origin.y};
            sprite.setPosition(temp_pos);
        }

        void set_coordinates_by_player_number(int player_number) {
            if (player_number == 1)
                origin.x = 140;
            else
                origin.x = 1780;
        }

        void update(void) {
            speed = (up ? -6 : 0) + (down ? 6 : 0);
            origin.y += speed;
            if (origin.y <= 67) origin.y = 67;
            if (origin.y >= 1080 - 135) origin.y  = 1080 - 135;
            sf::Vector2f temp_pos{origin.x, origin.y};
            sprite.setPosition(temp_pos);
        }

        void reset(void) {
            sf::Vector2f temp_pos{origin.x,  SCREEN_HEIGHT / 2};
            sprite.setPosition(temp_pos);
        }
};

class Player {
    public:
        int points {0};
        Racket racket;
        sf::Clock clock;
        sf::Text score;

        void initialize(int player_number) {
            racket.initialize_by_player_number(player_number);
            score.setFillColor(sf::Color::White);
            score.setOutlineColor(sf::Color::White);
            if (!font.loadFromFile("assets/Minecraft.ttf"))
                exit(EXIT_FAILURE);
            score.setCharacterSize(78);
            score.setFont(font);
            score.setString(std::to_string(points));
        }


        void update(int added_score = -1) {
            if (added_score == -1) {
                racket.update();
            } else {
                points += added_score;
                score.setString(std::to_string(points));
                racket.reset();
            }
        }
    private:
        sf::Font font;
};

class Game {
    public:
        sf::RenderWindow window;
        Player player1;
        Player player2;
        Ball ball;
        Sounds sounds;
        Game () {
            window.create(sf::VideoMode(1920, 1080), "Ponggo");
            window.setFramerateLimit(60);
            player1.initialize(1);
            player2.initialize(2);
            sf::Vector2f temp_pos{(float)(0.33 * SCREEN_WIDTH),  (float)(0.15 * SCREEN_HEIGHT)};
            player1.score.setPosition(temp_pos);
            sf::Vector2f temp_pos2{(float)(0.66 * SCREEN_WIDTH),  (float)(0.15 * SCREEN_HEIGHT)};
            player2.score.setPosition(temp_pos2);
        }
};

// Game functions
void game_loop(Game &pong, sf::Event event);
void handle_key_pressed(Game &pong, sf::Event event);
void handle_key_released(Game &pong, sf::Event event);
void ball_movement(Game &pong);

#endif