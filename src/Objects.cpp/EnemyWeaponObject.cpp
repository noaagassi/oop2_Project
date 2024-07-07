#include "Objects.h/EnemyWeaponObject.h"
#include "SoundsHandler.h"




EnemyWeaponObject::EnemyWeaponObject(Object_ID name, float speed, float fireRate)
	:BaseWeaponObject(), m_bulletName(name), m_bulletSpeed(speed),m_bulletFireRate(fireRate)
{    
}

void EnemyWeaponObject::shoot(sf::Vector2f enemyPos , sf::Vector2f playerPos)
{   
    auto laser = std::make_unique<LaserObject>(enemyPos);
    laser->setTarget(playerPos);
    laser->setBulletMembers(m_bulletName,m_bulletSpeed, m_bulletFireRate);
    m_bullet= std::move(laser);
    SoundsHandler::getInstance().playSound(Sound_Id::LASER_SHOOT);
    
}

std::unique_ptr<MovingObject> EnemyWeaponObject::retrieveBullet()
{
    if (m_bullet != nullptr)
    {
        return std::move(m_bullet);
    }
    return std::move(m_bullet);
}
