#pragma once

#include <SFML/Graphics.hpp>
#include "player.h"

class Raycast {

public:
    void rayCastPlayer(bool debug_mode, sf::RenderWindow& window, Player& player, World& world, sf::Texture& texture);

private:
    std::unique_ptr<sf::VertexArray> createLine(int x, int y, float angle);
};
