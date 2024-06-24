#include "Objects.h/LifeGiftObject.h"



bool LifeGiftObject::m_registerit = FactoryObject::registerit(LIFE_GIFT_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<LifeGiftObject>(pos); });

LifeGiftObject::LifeGiftObject(const sf::Vector2f& initPosition)
    :BaseGiftObject(initPosition)
{
    setObjTexture(LIFE_GIFT_OBJ);
}

LifeGiftObject::LifeGiftObject()
{
    setObjTexture(LIFE_GIFT_OBJ);
}
