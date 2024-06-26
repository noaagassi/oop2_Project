#pragma once
#include "MovingObject.h"

class BaseEnemyObject : public MovingObject
{
public:
    BaseEnemyObject(const sf::Vector2f& initPosition);
    BaseEnemyObject();
    void update(float deltatime, sf::RenderWindow* window) override;
    virtual void move(float deltaTime) = 0;
private:

};