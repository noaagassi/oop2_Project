#pragma once
#include "PlayerWeaponObject.h"

class SuperWeaponObject : public PlayerWeaponObject
{
public:
    SuperWeaponObject(const sf::Vector2f& initPosition);
    void shoot() override;

private:
    static bool m_registerit;
};