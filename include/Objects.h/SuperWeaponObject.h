#pragma once
#include "PlayerWeaponObject.h"

class SuperWeaponObject : public PlayerWeaponObject
{
public:
    SuperWeaponObject();
    void shoot(FlashlightObject flashlight) override;

private:
    static bool m_registerit;
};