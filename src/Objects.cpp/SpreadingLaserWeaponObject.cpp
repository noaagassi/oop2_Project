#include "Objects.h/SpreadingLaserWeaponObject.h"



bool SpreadingLaserWeaponObject::m_registerit = FactoryObject::registerit(SPREADING_LASER,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SpreadingLaserWeaponObject>(pos); });

SpreadingLaserWeaponObject::SpreadingLaserWeaponObject(const sf::Vector2f& initPosition)
    :PlayerWeaponObject(initPosition)
{
    m_fireRate = 3.0;
}

void SpreadingLaserWeaponObject::shoot()
{
}
