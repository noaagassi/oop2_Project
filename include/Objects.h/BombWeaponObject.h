#pragma once
#include "PlayerWeaponObject.h"

class BombWeaponObject : public PlayerWeaponObject
{
public:
    BombWeaponObject();
    void shoot(FlashlightObject flashight);

private:
    static bool m_registerit;
};