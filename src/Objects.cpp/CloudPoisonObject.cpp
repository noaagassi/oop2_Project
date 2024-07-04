

#include "Objects.h/CloudPoisonObject.h"
#include <iostream>
#include "SoundsHandler.h"


sf::Vector2f CloudPoisonObject::BounderiesOfPoison[2] = { {0.f, 0.f}, {0.f, 0.f} };

//----------------------------------------------------
CloudPoisonObject::CloudPoisonObject()
	:m_countingTime(sf::Time::Zero), m_limitTime(sf::seconds(13))
	//:m_frame(sf::Vector2f(200.f,200.f)), m_rectangleSize(5), m_countingTime(sf::Time::Zero),m_limitTime(sf::seconds(5))
{
	
	m_start.x = -60.0f,
		m_start.y = -70.0f;
	m_end.x = PLAY_WINDOW_WIDTH -25,
		m_end.y = PLAY_WINDOW_HEIGHT -20;
	BounderiesOfPoison[0] = m_start;
	BounderiesOfPoison[1] = m_end;

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
		SoundsHandler::getInstance().playSound(Sound_Id::POISON);
		update(m_countingTime);
	}
}
//----------------------------------------------------
void CloudPoisonObject::update(sf::Time elapse)
{
	int NEW_HEIGHT = PLAY_WINDOW_HEIGHT - 50;
	int NEW_WIDTH = PLAY_WINDOW_WIDTH - 70;
	float y_ratio = NEW_HEIGHT / MAP_HEIGHT,
		x_ratio = NEW_WIDTH / MAP_WIDTH;


	std::cout << "Updating rectangle size. Elapsed time: " << elapse.asSeconds() << " seconds" << std::endl; // הודעת דיבוג
	m_countingTime = sf::Time::Zero;
	//float y_ratio = PLAY_WINDOW_HEIGHT / MAP_HEIGHT,
	//	x_ratio = PLAY_WINDOW_WIDTH / MAP_WIDTH;
	m_start.x += x_ratio,
		m_start.y += y_ratio,
		m_end.x -= x_ratio,
		m_end.y -= y_ratio;
	resetBounderies(x_ratio, y_ratio);
	fillPoisonVector();
}
void CloudPoisonObject::fillPoisonVector()
{
	int NEW_HEIGHT = PLAY_WINDOW_HEIGHT - 50;
	int NEW_WIDTH = PLAY_WINDOW_WIDTH - 70;
	float y_ratio = NEW_HEIGHT / MAP_HEIGHT,
		x_ratio = NEW_WIDTH / MAP_WIDTH;
	sf::Vector2f start = m_start;

	for (start.x = m_start.x; start.x <= m_end.x; start.x += x_ratio)
	{
		m_poisons.push_back(std::make_unique<PoisonObject>(start));
	}
	for (start.x = m_start.x, start.y = m_start.y; start.y <= m_end.y; start.y += y_ratio)
	{
		m_poisons.push_back(std::make_unique<PoisonObject>(start));
	}
	for (start.x = m_start.x, start.y = m_end.y; start.x <= m_end.x; start.x += x_ratio)
	{
		m_poisons.push_back(std::make_unique<PoisonObject>(start));
	}
	for (start.x = m_end.x, start.y = m_start.y; start.y <= m_end.y; start.y += y_ratio)
	{
		m_poisons.push_back(std::make_unique<PoisonObject>(start));
	}

}
void CloudPoisonObject::resetBounderies(float x, float y)
{
	BounderiesOfPoison[0].x += x;
	BounderiesOfPoison[0].y += y;
	BounderiesOfPoison[1].x -= x;
	BounderiesOfPoison[1].y -= y;
	std::cout << "The current global boundaries are: (" << BounderiesOfPoison[0].x << ", " << BounderiesOfPoison[0].y << ") and ("
		<< BounderiesOfPoison[1].x << ", " << BounderiesOfPoison[1].y << ")" << std::endl;

}

std::vector<sf::Vector2f> CloudPoisonObject::getBoundaries() const 
{
	return std::vector<sf::Vector2f>
		(std::begin(BounderiesOfPoison), std::end(BounderiesOfPoison));
}
//----------------------------------------------------