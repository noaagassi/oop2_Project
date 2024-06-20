
#include "Objects.h/BallsWeaponObject.h"



bool BallsWeaponObject::m_registerit = FactoryObject::registerit(WEAPON_1_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BallsWeaponObject>(pos); });

BallsWeaponObject::BallsWeaponObject(const sf::Vector2f& initPosition)
{
}

BallsWeaponObject::BallsWeaponObject()
{
}
