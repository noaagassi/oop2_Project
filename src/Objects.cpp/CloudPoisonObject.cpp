#include "Objects.h/CloudPoisonObject.h"
#include <iostream>
//----------------------------------------------------
CloudPoisonObject::CloudPoisonObject()
	:m_frame(sf::Vector2f(200.f,200.f)), m_rectangleSize(5), m_countingTime(sf::Time::Zero),m_limitTime(sf::seconds(5))
{
	m_clock.restart();
	m_frame.setPosition(50.f, 50.f);
	m_frame.setOutlineColor(sf::Color::Red);
	m_frame.setOutlineThickness(m_rectangleSize);
	m_frame.setFillColor(sf::Color::Transparent);
}
//----------------------------------------------------
void CloudPoisonObject::draw(sf::RenderWindow* window)
{
	window->draw(m_frame);
}
//----------------------------------------------------
void CloudPoisonObject::update(float deltaTime, sf::RenderWindow* window)
{
	sf::Time delta = m_clock.getElapsedTime();
	m_countingTime += delta;
	m_clock.restart();

	if (m_countingTime >= m_limitTime)
	{
		update(m_countingTime);
	}
}
//----------------------------------------------------
void CloudPoisonObject::update(sf::Time elapse)
{
	std::cout << "Updating rectangle size. Elapsed time: " << elapse.asSeconds() << " seconds" << std::endl; // הודעת דיבוג
	m_countingTime = sf::Time::Zero;
	m_rectangleSize += 3;
	m_frame.setOutlineThickness(m_rectangleSize);
}
//----------------------------------------------------