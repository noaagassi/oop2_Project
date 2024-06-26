#pragma once
#include "Objects.h/PoisonObject.h"

class CloudPoisonObject
{
public:
	CloudPoisonObject();
	void draw(sf::RenderWindow*);
	void update(float,sf::RenderWindow*);
private:
	void update(sf::Time);

	//members
	sf::RectangleShape m_frame;
	float m_rectangleSize;
	sf::Clock m_clock;
	sf::Time m_countingTime;
	const sf::Time m_limitTime;
	
};