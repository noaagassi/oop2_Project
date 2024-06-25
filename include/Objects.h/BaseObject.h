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

	void setObjTexture(Object_ID name);    //abstract, private
	
	sf::Vector2f getSpriteLocation()const; 
	//void move(float offsetX, float offsetY);
	void draw(sf::RenderWindow* window) const;  //virtual??
	void setScale(float scaleX, float scaleY);  
	const sf::Sprite& getSprite() const;        
protected:
	
	sf::Sprite m_objectSprite;
	sf::Vector2f m_position;
};