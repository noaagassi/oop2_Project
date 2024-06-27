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

sf::FloatRect BaseObject::  getSpriteBounds() const
{
	return m_objectSprite.getGlobalBounds();
}


//-------------------------------------------------------
void BaseObject::draw(sf::RenderWindow* window) const
{
	window->draw(m_objectSprite);
}
//-------------------------------------------------------

//-------------------------------------------------------
void BaseObject:: setTheScale(float scaleX, float scaleY)
{
	m_objectSprite.setScale(scaleX, scaleY);

}
void BaseObject::setTheScale(Object_ID name)
{
    ///*m_objectSprite.setScale(scaleX, scaleY);*/


    sf::Vector2u theTextureSize = TextureHandler::getInstance().getObjTexture(name)->getSize();

    //// גודלי החלון שלך
    //float windowWidth = m_window->getSize().x;
    //float windowHeight = m_window->getSize().y;

    // חישוב ה-scale המתאים
    float scaleX = PLAY_WINDOW_WIDTH / (MAP_WIDTH * theTextureSize.x);
    float scaleY = PLAY_WINDOW_HEIGHT / (MAP_HEIGHT * theTextureSize.y);

    // קביעת ה-scale לספרייט של הרקע
	
	m_objectSprite.setScale(scaleX, scaleY);

}

//-------------------------------------------------------
const sf::Sprite& BaseObject::getSprite() const
{
	return m_objectSprite;
}
//--------------------------------------------------------
bool BaseObject::isCollidingWith( BaseObject& other) 
{
	 return  getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}
