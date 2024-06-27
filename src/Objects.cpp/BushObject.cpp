#include "Objects.h/BushObject.h"



bool BushObject::m_registerit = FactoryObject::registerit(BUSH_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BushObject>(pos); });

BushObject::BushObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition)
{
    setObjTexture(BUSH_OBJ);
    setTheScale(BUSH_OBJ);
}

BushObject::BushObject()
{
    setObjTexture(BUSH_OBJ);
}
