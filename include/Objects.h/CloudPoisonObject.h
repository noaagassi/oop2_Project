#pragma once
#include "Objects.h/PoisonObject.h"



class CloudPoisonObject
{
public:
	CloudPoisonObject();
	void draw(sf::RenderWindow*);
	void update(float,sf::RenderWindow*);
	std::vector<sf::Vector2f> getBoundaries() const;
private:
	void update(sf::Time);
	void fillPoisonVector();
	//members for vector of poison
	std::vector<std::shared_ptr<PoisonObject>> m_poisons;
	sf::Vector2f m_start;
	sf::Vector2f m_end;

	sf::Clock m_clock;
	sf::Time m_countingTime;
	const sf::Time m_limitTime;
	static sf::Vector2f BounderiesOfPoison[2];
	
	void resetBounderies(float, float);
	
};