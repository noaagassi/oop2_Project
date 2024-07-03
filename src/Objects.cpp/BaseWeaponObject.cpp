#include "Objects.h/BaseWeaponObject.h"




BaseWeaponObject::BaseWeaponObject()
	
{
}

void BaseWeaponObject::setFireRate(float rate)
{
	m_fireRate = rate;
}

void BaseWeaponObject::update(float deltaTime)
{
}

std::vector<std::unique_ptr<MovingObject>> BaseWeaponObject::retrieveBullets()
{
	std::vector<std::unique_ptr<MovingObject>> bullets;
	bullets.swap(m_bullets);
	return bullets;
}
