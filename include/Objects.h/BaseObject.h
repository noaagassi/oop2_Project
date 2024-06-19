#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"



class BaseObject {
public:
	void setObjTexture(Object_ID name);


	BaseObject(const sf::Vector2f& position) ;
	sf::Vector2f getSpriteLocation()const;
	void move(float offsetX, float offsetY);
	void draw(sf::RenderWindow& window) const;
	void setScale(float scaleX, float scaleY);
	const sf::Sprite& getSprite() const;
	//c-tor d-tor
	BaseObject() {};
	~BaseObject() {};

protected:
	sf::Sprite m_objectSprite;
};