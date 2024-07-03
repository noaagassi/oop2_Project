#pragma once
#include "PlayerWeaponObject.h"
#include "FlashlightObject.h"

class BallsWeaponObject : public PlayerWeaponObject
{
public:
    BallsWeaponObject(const sf::Vector2f& initPosition);
    BallsWeaponObject();
    void shoot(FlashlightObject flashlight) override;

private:
    static bool m_registerit;
    int m_numOfBalls;
};