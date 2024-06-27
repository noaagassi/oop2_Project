#include "Objects.h/BaseObject.h"
//---------------------------------------------------
BaseObject::BaseObject(const sf::Vector2f& position)
	:m_position(position.x,position.y)
{
	m_objectSprite.setPosition(m_position.x,m_position.y);
}

//---------------------------------------------------

void BaseObject::setObjTexture(Object_ID name)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
	m_objectSprite.setTexture(*texturePtr);
}

//---------------------------------------------------

sf::Vector2f BaseObject::getPosition() const
{
	return m_position;
}

void BaseObject::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}


//-------------------------------------------------------
void BaseObject::draw(sf::RenderWindow* window) const
{
	window->draw(m_objectSprite);
}
//-------------------------------------------------------

//-------------------------------------------------------
void BaseObject:: setScale(float scaleX, float scaleY)
{
	m_objectSprite.setScale(scaleX, scaleY);
}

//-------------------------------------------------------
sf::Sprite& BaseObject::getSprite() 
{
	return m_objectSprite;
}
//--------------------------------------------------------
bool BaseObject::isCollidingWith( BaseObject& other) 
{
	 return  getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}
