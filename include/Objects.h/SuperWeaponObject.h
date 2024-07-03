#pragma once
#include "PlayerWeaponObject.h"

class SuperWeaponObject : public PlayerWeaponObject
{
public:
    SuperWeaponObject();
    void shoot(FlashlightObject flashight) override;

private:
};