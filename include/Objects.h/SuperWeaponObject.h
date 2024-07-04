#pragma once
#include "PlayerWeaponObject.h"
#include "Objects.h/RocketObject.h"

class SuperWeaponObject : public PlayerWeaponObject
{
public:
    SuperWeaponObject();
    void shoot(FlashlightObject flashight) override;

private:
};