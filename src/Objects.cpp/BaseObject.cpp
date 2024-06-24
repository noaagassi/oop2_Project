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

sf::Vector2f BaseObject::getSpriteLocation() const {
	return m_objectSprite.getPosition();
}

//-------------------------------------------------------
//move to the moveing object
void BaseObject::move(float offsetX, float offsetY)
{
	m_objectSprite.move(offsetX, offsetY);
}

//-------------------------------------------------------
void BaseObject::draw(sf::RenderWindow* window) const
{
	window->draw(m_objectSprite);
}
//-------------------------------------------------------

void BaseObject:: setScale(float scaleX, float scaleY)
{
	m_objectSprite.setScale(scaleX, scaleY);
}

//-------------------------------------------------------
const sf::Sprite& BaseObject::getSprite() const
{
	return m_objectSprite;
}