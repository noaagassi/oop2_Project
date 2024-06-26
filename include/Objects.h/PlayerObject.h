#pragma once

#include "Objects.h/MovingObject.h"
#include "FactoryObject.h"
#include "FlashlightObject.h"

class PlayerObject : public MovingObject
{
public:
    //c-tor
    PlayerObject(const sf::Vector2f& pos);

    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);


private:
    //member of the texture of the player
    int spriteIndex;
    bool isMoving;

    sf::Clock clock;
    FlashlightObject m_flashlight;

    sf::IntRect getFrame(int row, int col);
    void handleInput();
    void animate(float deltaTime);
    static bool m_registerit;
};