
#include "Objects.h/BallsWeaponObject.h"


bool BallsWeaponObject::m_registerit = FactoryObject::registerit(BALLS_WEAPON_4,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BallsWeaponObject>(pos); });

BallsWeaponObject::BallsWeaponObject(const sf::Vector2f& initPosition)
{
    m_fireRate = 1.0f;
    setObjTexture(WALL_OBJ);
}

BallsWeaponObject::BallsWeaponObject()
{
    setObjTexture(WALL_OBJ);
}

void BallsWeaponObject::shoot()
{
}