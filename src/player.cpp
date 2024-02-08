#include "player.h"
#include "world.h"
#include <cmath>


void Player::init(int x, int y) {
    positionX = x;
    positionY = y;
    angle = 0.f;
}

constexpr double PI = 3.14159265358979323846;

void Player::rotate(float deltaAngle) {
    this->angle = std::fmod(angle + deltaAngle, 2 * PI);
}

void Player::move(Direction direction, World& world) {
    float sin_a = sin(angle);
    float cos_a = cos(angle);

    int newX = 0.f, newY = 0.f;
    if (direction == Direction::FORWARD) {
        newX = positionX + SPEED * cos_a;
        newY = positionY + SPEED * sin_a;
    } else if (direction == Direction::BACKWARD) {
        newX = positionX - SPEED * cos_a;
        newY = positionY - SPEED * sin_a;
    } else if (direction == Direction::LEFT) {
        newX = positionX + SPEED * sin_a;
        newY = positionY - SPEED * cos_a;
    } else if (direction == Direction::RIGHT) {
        newX = positionX - SPEED * sin_a;
        newY = positionY + SPEED * cos_a;
    }

    if (world.checkWall(newX, newY)) {
        positionX = newX;
        positionY = newY;
    }
}


