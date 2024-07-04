#pragma once
#include "PlayerWeaponObject.h"

class BombWeaponObject : public PlayerWeaponObject
{
public:
    BombWeaponObject();
    void shoot(FlashlightObject flashight) override;

private:
    static bool m_registerit;
};