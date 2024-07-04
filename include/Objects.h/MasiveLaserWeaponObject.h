#pragma once
#include "EnemyWeaponObject.h"

class MasiveLaserWeaponObject : public EnemyWeaponObject
{
public:
    MasiveLaserWeaponObject();
    void shoot(FlashlightObject flashight) override ;
private:
    static bool m_registerit;
};