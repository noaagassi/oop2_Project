#pragma once
#include "PlayerWeaponObject.h"

class RocketWeaponObject : public PlayerWeaponObject
{
public:
    RocketWeaponObject(const sf::Vector2f& initPosition);
    RocketWeaponObject();

private:
    static bool m_registerit;
};