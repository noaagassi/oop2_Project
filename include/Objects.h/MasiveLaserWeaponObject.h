#pragma once
#include "EnemyWeaponObject.h"

class MasiveLaserWeaponObject : public EnemyWeaponObject
{
public:
    MasiveLaserWeaponObject(const sf::Vector2f& initPosition);
    MasiveLaserWeaponObject();

private:
    static bool m_registerit;
};