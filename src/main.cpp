#include <iostream>
#include "player.h"
#include "SFML/Graphics.hpp"
#include "world.h"
#include "raycast.h"
#include "key_handler.h"
#include "SFML/Audio.hpp"

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 800;

int PLAYER_STARTING_X = 295;
int PLAYER_STARTING_Y = 350;

constexpr bool debug_mode = false;

int main() {
    // Create a sound buffer and load a WAV file
    sf::Music music;
    if (!music.openFromFile("theme.mp3")) {
        // Error handling if loading fails
        return EXIT_FAILURE;
    }
    music.play();

    Player player;
    player.init(PLAYER_STARTING_X, PLAYER_STARTING_Y);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Learn C++");

    World world(WINDOW_WIDTH, WINDOW_HEIGHT);

    Raycast raycast;

    sf::Texture textureWall;
    if (!textureWall.loadFromFile("texture.png")) {
        return EXIT_FAILURE;
    }

    sf::Texture textureSky;
    if (!textureSky.loadFromFile("sky.png")) {
        return EXIT_FAILURE;
    }

    sf::Vector2i previousMousePosition = sf::Mouse::getPosition(window);
    while (window.isOpen()) {
        checkKeyEvent(window, player, world, previousMousePosition);

        window.clear();
        world.drawWorld(debug_mode, window, textureSky);

        raycast.rayCastPlayer(debug_mode, window, player, world, textureWall);

        window.display();
    }

    return 0;
}
