#include "BaseObject.h"


//-------------------------------------------------------
BaseObject::BaseObject(const sf::Vector2f& position)
{
	//define the texture in the sprite
	m_objectSprite.setPosition(position);
}

//-------------------------------------------------------
//change from type int to type enum (of the texture)
void BaseObject::setObjTexture(Object_ID objectName)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(objectName);
	m_objectSprite.setTexture(*texturePtr);
}

//-------------------------------------------------------
sf::Vector2f BaseObject::getSpriteLocation() const 
{
	return m_objectSprite.getPosition();
}

//-------------------------------------------------------
//move to the moveing object
void BaseObject::move(float offsetX, float offsetY)
{
	m_objectSprite.move(offsetX, offsetY);
}

//-------------------------------------------------------
void BaseObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_objectSprite);
}

//-------------------------------------------------------
void BaseObject:: setSpriteScale(float scaleX, float scaleY)
{
	m_objectSprite.setScale(scaleX, scaleY);
}

//-------------------------------------------------------
const sf::Sprite& BaseObject::getSprite() const
{
	return m_objectSprite;
}