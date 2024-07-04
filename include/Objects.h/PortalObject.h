#pragma once
#include "StaticObject.h"

class PortalObject : public StaticObject
{
public:
    PortalObject(const sf::Vector2f& initPosition);
    PortalObject();
    
    PortalObject* getRandomPortal();

private:
    static std::vector<PortalObject*> allPortals;
    static bool m_registerit;
};