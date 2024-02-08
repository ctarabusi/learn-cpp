#pragma once

#include <string>

class Player {
public:
    Player(std::string name);
    
    std::string getName();
    int getPositionX(); 
    int getPositionY();

    void init(float x, float y);
    void move(float x, float y);


private:
    float positionX = 0.f;
    float positionY = 0.f;
    std::string name;

};