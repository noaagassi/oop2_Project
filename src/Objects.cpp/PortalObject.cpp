#include "Objects.h/PortalObject.h"



bool PortalObject::m_registerit = FactoryObject::registerit(PORTAL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PortalObject>(pos); });

PortalObject::PortalObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition)
{
    setObjTexture(PORTAL_OBJ);
}

PortalObject::PortalObject()
{
    setObjTexture(PORTAL_OBJ);
}
