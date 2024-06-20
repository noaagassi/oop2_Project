#pragma once
#include "StaticObject.h"

class PoisonObject : public StaticObject
{
public:
    PoisonObject(const sf::Vector2f& initPosition);
    PoisonObject();

private:
    static bool m_registerit;
};