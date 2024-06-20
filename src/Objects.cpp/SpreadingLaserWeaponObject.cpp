#include "Objects.h/SpreadingLaserWeaponObject.h"



bool SpreadingLaserWeaponObject::m_registerit = FactoryObject::registerit(WEAPON_3_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SpreadingLaserWeaponObject>(pos); });

SpreadingLaserWeaponObject::SpreadingLaserWeaponObject(const sf::Vector2f& initPosition)
{
}