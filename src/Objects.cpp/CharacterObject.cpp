#include"Objects.h/CharacterObject.h"

CharacterObject::CharacterObject(const sf::Vector2f& initPosition)
	:MovingObject(initPosition)
{
}

void CharacterObject::animate(float deltaTime)
{
}
/*
std::vector<std::unique_ptr<MovingObject>> CharacterObject::retrieveBullets()
{
	return m_currentWeapon->retrieveBullets();

}*/