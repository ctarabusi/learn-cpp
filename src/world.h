#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Obstacle {
    float x, y;
};

class GridCell {
public:
    int x, y;

    GridCell(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class World {

public:

    World(int width, int heigth);

    constexpr static int GRID_COUNT = 10;

    bool checkWall(int x, int y) const;
    GridCell getGridPosition(int x, int y) const;
    void drawWorld(bool debug_mode, sf::RenderWindow& window, sf::Texture& textureSky) const;

    int GRID_X_SIZE;
    int GRID_Y_SIZE;

    float width;
    float heigth;


private:
    std::vector<Obstacle> treasures;
    std::vector<Obstacle> obstacles;

    int gridX[10];
    int gridY[10];
};

