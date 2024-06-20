#pragma once
#include "StaticObject.h"

class PortalObject : public StaticObject
{
public:
    PortalObject(const sf::Vector2f& initPosition);
    PortalObject();

private:
    static bool m_registerit;
};