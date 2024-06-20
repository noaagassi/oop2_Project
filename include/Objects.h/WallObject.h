#pragma once
#include "StaticObject.h"

class WallObject : public StaticObject
{
public:
    WallObject(const sf::Vector2f& initPosition);
    WallObject();


private:
    static bool m_registerit;
};