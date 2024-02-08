#include "SFML/Graphics.hpp"
#include "player.h"

void checkKeyEvent(sf::Window& window, Player& player, World& world, sf::Vector2i& previousMousePosition) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::W) {
                    player.move(Direction::FORWARD, world);
                } else if (event.key.code == sf::Keyboard::A) {
                    player.move(Direction::LEFT, world);
                } else if (event.key.code == sf::Keyboard::S) {
                    player.move(Direction::BACKWARD, world);
                } else if (event.key.code == sf::Keyboard::D) {
                    player.move(Direction::RIGHT, world);
                }
                break;

            case sf::Event::MouseMoved:
                sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
                if (currentMousePosition.x < previousMousePosition.x) {
                    player.rotate(-0.05f);
                }
                else if (currentMousePosition.x > previousMousePosition.x) {
                    player.rotate(0.05f);
                }
                previousMousePosition = currentMousePosition;

                break;


        }
    }
}

