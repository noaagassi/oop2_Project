#include "Objects.h/PortalObject.h"
#include <iostream>


bool PortalObject::m_registerit = FactoryObject::registerit(PORTAL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PortalObject>(pos); });

std::vector<PortalObject*> PortalObject::allPortals;

PortalObject::PortalObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition) 
{
    allPortals.push_back(this);
    setTheScale(PORTAL_OBJ);
    setObjTexture(PORTAL_OBJ);
}

PortalObject::PortalObject()
{
    allPortals.push_back(this);
    setObjTexture(PORTAL_OBJ);
}


PortalObject* PortalObject::getRandomPortal()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    size_t randomIndex;
    do {
        randomIndex = std::rand() % PortalObject::allPortals.size();
    } while (PortalObject::allPortals[randomIndex] == this);

    return PortalObject::allPortals[randomIndex];
}