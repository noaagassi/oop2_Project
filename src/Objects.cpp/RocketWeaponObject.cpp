#include "Objects.h/RocketWeaponObject.h"



bool RocketWeaponObject::m_registerit = FactoryObject::registerit(ROCKET_WEAPON_2_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<RocketWeaponObject>(pos); });

RocketWeaponObject::RocketWeaponObject(const sf::Vector2f& initPosition)
{
    setObjTexture(ROCKET_WEAPON_2_OBJ);
}

RocketWeaponObject::RocketWeaponObject()
{
    setObjTexture(ROCKET_WEAPON_2_OBJ);
}
