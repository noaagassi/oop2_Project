#include "Objects.h/PoisonObject.h"



bool PoisonObject::m_registerit = FactoryObject::registerit(POISON_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PoisonObject>(pos); });

PoisonObject::PoisonObject(const sf::Vector2f& initPosition)
{
    setObjTexture(POISON_OBJ);
}

PoisonObject::PoisonObject()
{
    setObjTexture(POISON_OBJ);
}
