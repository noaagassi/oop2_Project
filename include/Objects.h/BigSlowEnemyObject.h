#pragma once
#include "BaseEnemyObject.h"

class BigSlowEnemyObject : public BaseEnemyObject
{
public:
    BigSlowEnemyObject(const sf::Vector2f& initPosition);
    void move(float deltaTime) override;
    virtual void handleInput();

private:
    static bool m_registerit;
};