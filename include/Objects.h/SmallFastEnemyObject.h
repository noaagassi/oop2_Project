#pragma once
#include "BaseEnemyObject.h"

class SmallFastEnemyObject : public BaseEnemyObject
{
public:
    SmallFastEnemyObject(const sf::Vector2f& initPosition);
    void move(float deltaTime) override;
    virtual void handleInput();
private:
    static bool m_registerit;
};