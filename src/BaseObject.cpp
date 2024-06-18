#include "Objects.h/BaseObject.h"

BaseObject::BaseObject(const sf::Texture& texture, const sf::Vector2f& position)
{
	m_objectSprite.setPosition(position);
	m_objectSprite.setTexture(texture);
}

sf::Vector2f BaseObject::getSpriteLocation() const {
	return m_objectSprite.getPosition();
}

void BaseObject::move(float offsetX, float offsetY)
{
	m_objectSprite.move(offsetX, offsetY);
}


void BaseObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_objectSprite);
}

void BaseObject:: setSpriteScale(float scaleX, float scaleY)
{
	m_objectSprite.setScale(scaleX, scaleY);
}


const sf::Sprite& BaseObject::getSprite() const
{
	return m_objectSprite;
}