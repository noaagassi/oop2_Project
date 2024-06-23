
#include "Objects.h/MasiveLaserWeaponObject.h"



bool MasiveLaserWeaponObject::m_registerit = FactoryObject::registerit(WEAPON_ENEMY_1_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<MasiveLaserWeaponObject>(pos); });

MasiveLaserWeaponObject::MasiveLaserWeaponObject(const sf::Vector2f& initPosition)
{
    setObjTexture(MASSIVE_LASER_WEAPON_3_OBJ);
}

MasiveLaserWeaponObject::MasiveLaserWeaponObject()
{
    setObjTexture(MASSIVE_LASER_WEAPON_3_OBJ);
}
