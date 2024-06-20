#pragma once
#include "BaseEnemyObject.h"

class SmallFastEnemyObject : public BaseEnemyObject
{
public:
    SmallFastEnemyObject(const sf::Vector2f& initPosition);


private:
    static bool m_registerit;
};