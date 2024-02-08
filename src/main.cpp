#include <iostream>
#include "player.h"
#include "keyboard_handling.h"
#include <SFML/Graphics.hpp>

int main() {

    Player player("Christian");
    std::cout << player.getName() << std::endl;

    player.init(395.f, 295.f);

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dot Drawing");

    // Create a dot shape
    sf::CircleShape dot(10.f);
    dot.setFillColor(sf::Color::Red);
    dot.setPosition(player.getPositionX(), player.getPositionY()); // Position the dot in the center of the window initially

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {
                    // W key pressed
                    player.move(0, -1.f);
                } else if (event.key.code == sf::Keyboard::A) {
                    player.move(-1.f, 0);
                } else if (event.key.code == sf::Keyboard::S) {
                    player.move(0, 1.0f);
                } else if (event.key.code == sf::Keyboard::D) {
                    player.move(1.f, 0);
                } else if (event.key.code == sf::Keyboard::Q) {
                    // Q key pressed
                }
            }

            dot.setPosition(player.getPositionX(), player.getPositionY()); // Position the dot in the center of the window initially
        }

        // Clear the window
        window.clear();

        // Draw the dot
        window.draw(dot);

        // Display the window
        window.display();
    }

    return 0;
}