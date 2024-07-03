#pragma once
#include "PlayerWeaponObject.h"

class SpreadingLaserWeaponObject : public PlayerWeaponObject
{
public:
    SpreadingLaserWeaponObject();
    void shoot(FlashlightObject flashight) override;

private:
};