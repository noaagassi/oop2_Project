#include "Objects.h/PlayerWeaponObject.h"




PlayerWeaponObject::PlayerWeaponObject()
	:BaseWeaponObject()
{
}

void PlayerWeaponObject::addBall()
{
	m_numOfBalls+=2;
}