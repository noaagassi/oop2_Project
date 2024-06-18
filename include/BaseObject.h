#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"



class BaseObject {
public:
	void setObjTexture(int objNum);


	BaseObject(const sf::Vector2f& position) ;
	sf::Vector2f getSpriteLocation()const;
	void move(float offsetX, float offsetY);
	void draw(sf::RenderWindow& window) const;
	void setSpriteScale(float scaleX, float scaleY);
	const sf::Sprite& getSprite() const;
	//c-tor d-tor
	BaseObject() {};
	~BaseObject() {};

private:
	sf::Sprite m_objectSprite;
	sf::Vector2f m_location;
};