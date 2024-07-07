#include "Objects.h/LaserObject.h"



//-----------------------------------------------
bool LaserObject::m_registerit = FactoryObject::registerit(REGULAR_LASER_WEAPON_1_OBJ,
	[](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<LaserObject>(pos); });
//------------------------------------------------------------
LaserObject::LaserObject(const sf::Vector2f& position)
	:BulletObject(position)
{
	m_speed = 100.0f;
	setObjTexture(REGULAR_LASER_WEAPON_1_OBJ);
	setTheScale(0.02f, 0.02f);
}
//----------------------------------------------------------------
void LaserObject::update(float deltaTime, sf::RenderWindow* window)
{
	m_position += m_direction * m_speed * deltaTime;
	m_objectSprite.setPosition(m_position);
	
	if ((m_target.x - m_position.x) <= 5
		&& (m_target.x - m_position.x) >= -5
		&& (m_target.y - m_position.y) <= 5
		&& (m_target.y - m_position.y) >= -5)
	{
		m_toDelete = true;
	}
}
//----------------------------------------------------------------


