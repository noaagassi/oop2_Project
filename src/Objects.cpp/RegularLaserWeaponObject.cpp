#include "Objects.h/RegularLaserWeaponObject.h"



bool RegularLaserWeaponObject::m_registerit = FactoryObject::registerit(WEAPON_ENEMY_2_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<RegularLaserWeaponObject>(pos); });

RegularLaserWeaponObject::RegularLaserWeaponObject(const sf::Vector2f& initPosition)
{
    setObjTexture(REGULAR_LASER_WEAPON_1_OBJ);
}

RegularLaserWeaponObject::RegularLaserWeaponObject()
{
    setObjTexture(REGULAR_LASER_WEAPON_1_OBJ);
}
