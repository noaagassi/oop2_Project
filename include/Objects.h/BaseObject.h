//need to do:
// add in the constractur of every onject a init to base constarctr



#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "TextureHandler.h"
//#include "FactoryObject.h"

class BaseObject 
{
public:

	//c-tor d-tor
	BaseObject() {};
	virtual ~BaseObject() = default;
	BaseObject(const sf::Vector2f& position) ;

	void setObjTexture(Object_ID name);
	sf::Vector2f getSpriteLocation()const;
	virtual void draw(sf::RenderWindow* window) const;
	void setScale(float scaleX, float scaleY);
	const sf::Sprite& getSprite() const;

	bool isCollidingWith(const BaseObject& other) const;
	

protected:
	
	sf::Sprite m_objectSprite;
	sf::Vector2f m_position;
};