#include "Objects.h/EnemyWeaponObject.h"
#include <iostream>



EnemyWeaponObject::EnemyWeaponObject(Object_ID WeaponName, float weaponSpeed, float fireRate)
	:BaseWeaponObject(),m_weaponName(WeaponName), m_weaponSpeed(weaponSpeed), m_fireRate(fireRate)
{
	
}

void EnemyWeaponObject::shoot(sf::Vector2f enemyPos, sf::Vector2f playerPos)
{
    
    auto bullet = std::make_unique<LaserObject>(enemyPos);
    bullet->setTarget(playerPos);
    bullet->setMembers(m_weaponName, m_weaponSpeed, m_fireRate);
    m_bullets.push_back(std::move(bullet));
    std::cout << "agregando laser" << std::endl;
        
    //SoundsHandler::getInstance().playSound(Sound_Id::BALL_SHOOT);
    
}
