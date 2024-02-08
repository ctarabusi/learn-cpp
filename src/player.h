#pragma once

#include <SFML/Graphics.hpp>
#include "world.h"

const int SPEED = 10;

enum class Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Player {
public:
    int positionX = 0;
    int positionY = 0;
    float angle = 0.f;

    void init(int x, int y);
    void move(Direction direction, World& world);
    void rotate(float angle);

    void printPlayer(sf::RenderWindow& window, World& world);
};