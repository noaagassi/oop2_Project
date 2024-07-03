#pragma once
#include "PlayerWeaponObject.h"

class SpreadingLaserWeaponObject : public PlayerWeaponObject
{
public:
    SpreadingLaserWeaponObject();
    void shoot(FlashlightObject flashlight) override;

private:
    static bool m_registerit;
};