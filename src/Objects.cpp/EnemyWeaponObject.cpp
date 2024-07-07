#include "Objects.h/EnemyWeaponObject.h"
#include "SoundsHandler.h"




EnemyWeaponObject::EnemyWeaponObject()
	:BaseWeaponObject()
{
	m_fireRate = 1.0f;
}

void EnemyWeaponObject::shoot(sf::Vector2f enemyPos , sf::Vector2f playerPos)
{   
    auto laser = std::make_unique<LaserObject>(enemyPos);
    laser->setTarget(playerPos);
    m_bullet= std::move(laser);
    SoundsHandler::getInstance().playSound(Sound_Id::LASER_SHOOT);
    
}

std::unique_ptr<MovingObject> EnemyWeaponObject::retrieveBullet()
{
    
    return std::move(m_bullet);
}
