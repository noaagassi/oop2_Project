#pragma once
#include "BaseWeaponObject.h"
#include "LaserObject.h"


class EnemyWeaponObject : public BaseWeaponObject
{
public:
    EnemyWeaponObject();
    void shoot(sf::Vector2f enemyPos, sf::Vector2f playerPos);
    std::unique_ptr<MovingObject> retrieveBullet();
private:
   std::unique_ptr<MovingObject> m_bullet;
};