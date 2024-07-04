#pragma once
#include "EnemyWeaponObject.h"

class RegularLaserWeaponObject : public EnemyWeaponObject
{
public:
    RegularLaserWeaponObject();
    void shoot(FlashlightObject flashight) override;
private:
    static bool m_registerit;
};