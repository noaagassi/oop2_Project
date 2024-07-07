#pragma once
#include "BaseWeaponObject.h"
#include "LaserObject.h"


class EnemyWeaponObject : public BaseWeaponObject
{
public:
    EnemyWeaponObject(Object_ID,float speed, float fireRate);
    void shoot(sf::Vector2f enemyPos, sf::Vector2f playerPos);
    std::unique_ptr<MovingObject> retrieveBullet();
private:
   std::unique_ptr<MovingObject> m_bullet;
   float m_bulletSpeed;
   float m_bulletFireRate;
   Object_ID m_bulletName;
};