#include "Objects.h/CloudPoisonObject.h"
#include <iostream>
//----------------------------------------------------
CloudPoisonObject::CloudPoisonObject()
	:m_countingTime(sf::Time::Zero), m_limitTime(sf::seconds(5))
	//:m_frame(sf::Vector2f(200.f,200.f)), m_rectangleSize(5), m_countingTime(sf::Time::Zero),m_limitTime(sf::seconds(5))
{
	m_start.x = 150.0f,
		m_start.y = 150.0f;
	m_end.x = 200.0f,
		m_end.y = 200.0f;
	m_clock.restart();
	fillPoisonVector();
}
//----------------------------------------------------
void CloudPoisonObject::draw(sf::RenderWindow* window)
{
	for (auto& poison : m_poisons)
	{
		poison->draw(window);
	}
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
	//מעדכנת את המיקומים אליהם אני רוצה להדפיס ומוסיפה לוקטור את הרעלים הרלוונטים
}
void CloudPoisonObject::fillPoisonVector()
{
	float ratio = 20.0f;
	sf::Vector2f start = m_start;

	for (start.x = m_start.x; start.x <= m_end.x; start.x += ratio)
	{
		m_poisons.push_back(std::make_unique<PoisonObject>(start));
	}
}
//----------------------------------------------------