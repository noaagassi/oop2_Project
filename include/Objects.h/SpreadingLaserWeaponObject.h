#pragma once
#include "PlayerWeaponObject.h"

class SpreadingLaserWeaponObject : public PlayerWeaponObject
{
public:
    SpreadingLaserWeaponObject(const sf::Vector2f& initPosition);


private:
    static bool m_registerit;
};