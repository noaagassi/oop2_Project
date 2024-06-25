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
	BaseObject(const sf::Vector2f& position);
	virtual ~BaseObject() = default;

protected:
	
	sf::Sprite m_objectSprite;
	sf::Vector2f m_position;
};