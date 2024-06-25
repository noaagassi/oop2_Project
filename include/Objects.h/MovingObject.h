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
    virtual ~MovingObject() = default;
    void setObjTexture(Object_ID id);
    void setScale(float x, float y);
    sf::IntRect getFrame(int row, int col);
    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
    virtual void move(float deltaTime) = 0;

protected:
    void animate(float deltaTime);

    sf::Sprite m_objectSprite;
    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;
    int spriteIndex;
    bool isMoving;
    sf::Clock clock;
};
