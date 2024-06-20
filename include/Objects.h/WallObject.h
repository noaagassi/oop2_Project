#pragma once
#include "StaticObject.h"

class WallObject : public StaticObject
{
public:
    WallObject(const sf::Vector2f& initPosition);


private:
    static bool m_registerit;
};