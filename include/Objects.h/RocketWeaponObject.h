#pragma once
#include "PlayerWeaponObject.h"

class RocketWeaponObject : public PlayerWeaponObject
{
public:
    RocketWeaponObject();
    void shoot(FlashlightObject flashlight) override;

private:
    static bool m_registerit;
};