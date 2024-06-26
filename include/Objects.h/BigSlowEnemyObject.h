#pragma once
#include "BaseEnemyObject.h"

class BigSlowEnemyObject : public BaseEnemyObject
{
public:
    BigSlowEnemyObject(const sf::Vector2f& initPosition);
    void move(float deltaTime) override;
    void handleInput();

private:
    static bool m_registerit;
};