#pragma once
#include "StaticObject.h"

class PortalObject : public StaticObject
{
public:
    PortalObject(const sf::Vector2f& initPosition);
    PortalObject();
    void setPortals(std::shared_ptr<std::vector<std::shared_ptr<PortalObject>>> portals);

    PortalObject& getRandomPortal();

private:
    std::shared_ptr<std::vector<std::shared_ptr<PortalObject>>> m_ptr2portals;
    static bool m_registerit;
};