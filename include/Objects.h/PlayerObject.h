#pragma once

#include "Objects.h/MovingObject.h"
#include "FactoryObject.h"
#include "FlashlightObject.h"

class PlayerObject : public MovingObject
{
public:
    //c-tor
    PlayerObject(const sf::Vector2f& pos);

    void update(float deltaTime, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    //member of the texture of the player

    float m_x, m_y;
    int spriteIndex;
    bool isMoving;
    sf::Clock clock;
    FlashlightObject m_flashlight;

    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;

    sf::IntRect getFrame(int row, int col);
    void handleInput(sf::Keyboard::Key key);
    void animate(float deltaTime);
    static bool m_registerit;
};
