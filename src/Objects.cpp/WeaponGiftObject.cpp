#include "Objects.h/WeaponGiftObject.h"



bool WeaponGiftObject::m_registerit = FactoryObject::registerit(WEAPON_GIFT_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<WeaponGiftObject>(pos); });

WeaponGiftObject::WeaponGiftObject(const sf::Vector2f& initPosition)
{
}

WeaponGiftObject::WeaponGiftObject()
{
}
