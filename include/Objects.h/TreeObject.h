#pragma once
#include "StaticObject.h"

class TreeObject : public StaticObject
{
public:
    TreeObject(const sf::Vector2f& initPosition);
    TreeObject();


private:
    static bool m_registerit;
};