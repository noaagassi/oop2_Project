#include "Objects.h/BaseWeaponObject.h"




BaseWeaponObject::BaseWeaponObject(const sf::Vector2f& initPosition)
	:StaticObject(initPosition)
{
}

BaseWeaponObject::BaseWeaponObject()
{
}

void BaseWeaponObject::setFireRate(float rate)
{
	m_fireRate = rate;
}
