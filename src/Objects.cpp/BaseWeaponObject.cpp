#include "Objects.h/BaseWeaponObject.h"
#include <iostream>




BaseWeaponObject::BaseWeaponObject()
{
}

void BaseWeaponObject::setFireRate(float rate)
{
	m_fireRate = rate;
}

void BaseWeaponObject::update(float deltaTime,sf::RenderWindow* window)
{
    for (auto it = m_bullets.begin(); it != m_bullets.end();) {
        (*it)->update(deltaTime,window);
        if ((*it)->toDelete()) {
            it = m_bullets.erase(it);
        }
        else {
            ++it;
        }
    }
}

std::vector<std::unique_ptr<MovingObject>> BaseWeaponObject::retrieveBullets()
{
	std::vector<std::unique_ptr<MovingObject>> bullets;
	bullets.swap(m_bullets);
	return bullets;
}

void BaseWeaponObject::draw(sf::RenderWindow* window)
{
    for (auto it = m_bullets.begin(); it != m_bullets.end();) 
    {
        (*it)->draw( window);
        ++it;
    }
}
