#pragma once
#include "EnemyWeaponObject.h"

class RegularLaserWeaponObject : public EnemyWeaponObject
{
public:
    RegularLaserWeaponObject(const sf::Vector2f& initPosition);
    RegularLaserWeaponObject();
    void shoot() override;
private:
    static bool m_registerit;
};