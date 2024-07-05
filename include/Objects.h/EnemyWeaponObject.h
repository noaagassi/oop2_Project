#pragma once
#include "BaseWeaponObject.h"
#include "LaserObject.h"
class EnemyWeaponObject : public BaseWeaponObject
{
public:
    EnemyWeaponObject(Object_ID WeaponName, float weaponSpeed, float fireRate);
    void shoot(sf::Vector2f enemyPos, sf::Vector2f playerPos);

private:
    Object_ID m_weaponName;
    float m_weaponSpeed;
    float m_fireRate;
};