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

void BushObject::resetColor()
{
    sf::Color color = m_objectSprite.getColor();
    color.a = 255;  
    m_objectSprite.setColor(color);
}

void BushObject::makeTranslucent()
{
    sf::Color color = m_objectSprite.getColor();
    color.a = 128;
    m_objectSprite.setColor(color);
}