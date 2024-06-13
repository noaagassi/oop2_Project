#pragma once
#include <SFML/Graphics.hpp>

class BaseObject
{
private:
	sf::Vector2f m_location;
	sf::Sprite m_pic;
public:
	//c-tor d-tor
	BaseObject() {};
	~BaseObject() {};

	//location functions
	//void setLocation(float x, float y) { m_location.x = x, m_location.y = y };
	//sf::Vector2f getLocation() const { return m_location };
};