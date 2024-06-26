#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "BaseObject.h"
#include "FactoryObject.h"
#include "Utilities.h"

class MovingObject : public BaseObject
{
public:
    MovingObject(const sf::Vector2f& initPosition);
    MovingObject();
    virtual void update(float deltatime, sf::RenderWindow* window) = 0;
    void goLeft();
    void goRight();
    void goUp();
    void goDown();

protected:
    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;

    float m_speed;
    bool m_isMoving;
    sf::Vector2f m_direction;
};