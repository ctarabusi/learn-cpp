#include "world.h"

#include "player.h"

constexpr int ROWS = 10;
constexpr int COLS = 10;

// Define the labyrinth matrix
char labyrinth[ROWS][COLS] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', '_', '_', '_', '_', '_', '_', '_', '_', 'X'},
    {'X', '_', '_', 'X', 'X', 'X', '_', '_', '_', 'X'},
    {'X', '_', '_', 'X', 'T', 'X', '_', 'X', '_', 'X'},
    {'X', '_', '_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', '_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', '_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', '_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', '_', '_', '_', '_', '_', '_', '_', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
};
World::World(int width, int heigth) {
    this->width = width;
    this->heigth = heigth;

    GRID_X_SIZE = width / GRID_COUNT;
    GRID_Y_SIZE = width / GRID_COUNT;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (labyrinth[i][j] == 'X') {
                Obstacle obstacle;
                obstacle.x = i * GRID_X_SIZE;
                obstacle.y = j * GRID_Y_SIZE;
                obstacles.push_back(obstacle);
            }
            else if (labyrinth[i][j] == 'T') {
                Obstacle treasure;
                treasure.x = i * GRID_X_SIZE;
                treasure.y = j * GRID_Y_SIZE;
                treasures.push_back(treasure);
            }
        }
    }

    for (int i = 0; i < GRID_COUNT; i++) {
        gridX[i] = GRID_X_SIZE * i;
        gridY[i] = GRID_Y_SIZE * i;
    }
}


void World::drawWorld(bool debug_mode, sf::RenderWindow& window, sf::Texture& textureSky) const {

    if (debug_mode) {
        for (int i = 0; i < obstacles.size(); i++) {
            sf::RectangleShape obstacle(sf::Vector2f(GRID_X_SIZE, GRID_Y_SIZE));
            obstacle.setFillColor(sf::Color::White);
            obstacle.setOutlineColor(sf::Color::White);
            obstacle.setPosition(obstacles[i].x, obstacles[i].y);

            window.draw(obstacle);
        }

        for (int i = 0; i < GRID_COUNT; i++) {
            sf::VertexArray horizontalLine(sf::Lines, 2);
            horizontalLine[0].position = sf::Vector2f(gridX[i], 0);
            horizontalLine[0].color = sf::Color::White;
            horizontalLine[1].position = sf::Vector2f(gridX[i], heigth);
            horizontalLine[1].color = sf::Color::White;
            window.draw(horizontalLine);

            sf::VertexArray verticalLine(sf::Lines, 2);
            verticalLine[0].position = sf::Vector2f(0, gridY[i]);
            verticalLine[0].color = sf::Color::White;
            verticalLine[1].position = sf::Vector2f(width, gridY[i]);
            verticalLine[1].color = sf::Color::White;
            window.draw(verticalLine);
        }
    }
    else {
        sf::RectangleShape sky(sf::Vector2f(width, heigth / 2));
        sky.setPosition(0, 0);
        sky.setTexture(&textureSky);
        window.draw(sky);

        sf::RectangleShape floor(sf::Vector2f(width, heigth / 2));
        floor.setPosition(0, heigth / 2);
        floor.setFillColor(sf::Color(30, 30, 30));
        window.draw(floor);
    }
}



bool World::checkWall(int x, int y) const {
    for (int i = 0; i < obstacles.size(); i++) {
        if ((x >= obstacles[i].x) && (x < obstacles[i].x + GRID_X_SIZE) && (y >= obstacles[i].y) && (y < obstacles[i].y + GRID_Y_SIZE)) {
            return false;
        }
    }
    return true;
}

GridCell World::getGridPosition(int x, int y) const {
    int foundX = 0;
    int foundY = 0;
    for (int i = 0; i < GRID_COUNT; i++) {
        if (x >= GRID_X_SIZE * i && x < GRID_X_SIZE * (i + 1)) {
            foundX = i;
            break;
        }
    }

    for (int i = 0; i < GRID_COUNT; i++) {
        if (y >= GRID_Y_SIZE * i && y < GRID_Y_SIZE * (i + 1)) {
            foundY = i;
            break;
        }
    }
    return GridCell(foundX, foundY);
}



