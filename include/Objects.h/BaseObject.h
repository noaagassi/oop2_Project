//need to do:
// add in the constractur of every onject a init to base constarctr



#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "TextureHandler.h"
#include "Utilities.h"
//#include "FactoryObject.h"

class BaseObject 
{
public:

	//c-tor d-tor
	BaseObject() {};
	virtual ~BaseObject() = default;
	void setObjTexture(Object_ID name);

	BaseObject(const sf::Vector2f& position) ;
	//void setObjTexture(Object_ID);
	sf::Vector2f getSpriteLocation()const;
	sf::FloatRect getSpriteBounds() const;



	sf::Vector2f getPosition()const;
	void setPosition(sf::Vector2f);
	virtual void draw(sf::RenderWindow* window) const;
	void setTheScale(float scaleX, float scaleY);
	void setTheScale(Object_ID name);
	const sf::Sprite& getSprite() const;
	

	bool isCollidingWith( BaseObject& other) ;
	

protected:
	
	sf::Sprite m_objectSprite;
	sf::Vector2f m_position;
};