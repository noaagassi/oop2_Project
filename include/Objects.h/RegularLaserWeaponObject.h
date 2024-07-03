#pragma once
#include "EnemyWeaponObject.h"

class RegularLaserWeaponObject : public EnemyWeaponObject
{
public:
    RegularLaserWeaponObject();
    void shoot(FlashlightObject flashlight) override;
private:
    static bool m_registerit;
};