#pragma once
#include "EnemyWeaponObject.h"

class MasiveLaserWeaponObject : public EnemyWeaponObject
{
public:
    MasiveLaserWeaponObject();
    void shoot(FlashlightObject flashlight) override;
private:
    static bool m_registerit;
};