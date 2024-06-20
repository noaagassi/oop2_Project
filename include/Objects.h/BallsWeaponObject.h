#pragma once
#include "PlayerWeaponObject.h"

class BallsWeaponObject : public PlayerWeaponObject
{
public:
    BallsWeaponObject(const sf::Vector2f& initPosition);
    BallsWeaponObject();

private:
    static bool m_registerit;
};