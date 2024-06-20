#pragma once
#include "BaseEnemyObject.h"

class BigSlowEnemyObject : public BaseEnemyObject
{
public:
    BigSlowEnemyObject(const sf::Vector2f& initPosition);


private:
    static bool m_registerit;
};