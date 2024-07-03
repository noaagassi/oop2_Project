#include "Objects.h/BulletObject.h"

BulletObject::BulletObject(const sf::Vector2f& position)
	:MovingObject(position),m_toDelete(false)
{
}

sf::FloatRect BulletObject::getBounds() const
{
	return m_objectSprite.getGlobalBounds();
}

bool BulletObject::toDelete()
{
	return m_toDelete;
}

void BulletObject::toDelete(bool x)
{
	m_toDelete = x;
}

void BulletObject::setTarget(const sf::Vector2f& target)
{
	m_target = target;

	sf::Vector2f direction = m_target - m_position;
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		m_direction = direction / length;
	}

}
