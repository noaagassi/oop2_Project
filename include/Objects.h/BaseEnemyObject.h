#pragma once
#include "MovingObject.h"

class BaseEnemyObject : public MovingObject
{
public:
    BaseEnemyObject(const sf::Vector2f& initPosition);
    BaseEnemyObject();
   // virtual void move(float deltaTime) = 0;
private:

};