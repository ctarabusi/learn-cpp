#include "player.h"

Player::Player(std::string name): name(name) {}

std::string Player::getName() {
    return name;      
}

int Player::getPositionX() {
    return positionX;          
}

int Player::getPositionY() {
    return positionY;  
}

void Player::init(float x, float y) {
    positionX = x;
    positionY = y;
}

void Player::move(float x, float y) {
    positionX += x;
    positionY += y;
}