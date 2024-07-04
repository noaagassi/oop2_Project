

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "TextureHandler.h"
#include "Utilities.h"

class BaseObject 
{
public:

	BaseObject() {};
	virtual ~BaseObject() = default;
	void setObjTexture(Object_ID name);

	BaseObject(const sf::Vector2f& position) ;
	//sf::Vector2f getSpriteLocation()const;
	sf::FloatRect getSpriteBounds() const;



	sf::Vector2f getPosition()const;
	void setPosition(sf::Vector2f);
	virtual void draw(sf::RenderWindow* window) const;
	void setTheScale(float scaleX, float scaleY);
	void setTheScale(Object_ID name);
	const sf::Sprite& getSprite() const;
	void setSpriteColor(const sf::Color& color);

	bool isCollidingWith( BaseObject& other) ;
	

protected:
	
	sf::Sprite m_objectSprite;
	sf::Vector2f m_position;
};