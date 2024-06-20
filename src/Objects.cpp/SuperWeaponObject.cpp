#include "Objects.h/SuperWeaponObject.h"



bool SuperWeaponObject::m_registerit = FactoryObject::registerit(WEAPON_SUPER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SuperWeaponObject>(pos); });

SuperWeaponObject::SuperWeaponObject(const sf::Vector2f& initPosition)
{
}