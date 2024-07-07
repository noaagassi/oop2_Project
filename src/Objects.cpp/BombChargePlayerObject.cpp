#include "Objects.h/BombChargePlayerObject.h"
//--------------------------------------------
BombChargePlayerObject::BombChargePlayerObject(float x, float y)
{
	m_isCharge = false;
	sf::Vector2f vec(x, y);
	setRectangles();
	setPosition(vec);
}
//--------------------------------------------
void BombChargePlayerObject::update(sf::Vector2f pos, float addTime)
{
	resizeBomb(addTime);
	setPosition(pos);
}
//--------------------------------------------
void BombChargePlayerObject::draw(sf::RenderWindow* window) const
{
	window->draw(m_background);
	window->draw(m_bombCharge);
}
//--------------------------------------------
bool BombChargePlayerObject::isCharge()
{
	if (m_isCharge)
	{
		return true;
	}
	return false;
}
//--------------------------------------------
void BombChargePlayerObject::restartCharge()
{
	sf::Vector2f newSize(0, m_bombCharge.getSize().y);
	m_bombCharge.setSize(newSize);
	m_isCharge = false;
}
//--------------------------------------------
void BombChargePlayerObject::resizeBomb(float time)
{
	sf::Vector2f newSize(m_bombCharge.getSize().x + time+0.004, m_bombCharge.getSize().y);
	m_bombCharge.setSize(newSize);
	if (m_bombCharge.getSize().x >= LIMIT_SIZE)
	{
		newSize.x = LIMIT_SIZE;
		m_bombCharge.setSize(newSize);
		m_isCharge = true;
	}
}
//--------------------------------------------
void BombChargePlayerObject::setRectangles()
{
	setSize();
	setColor();
	setScale();
}
//--------------------------------------------
void BombChargePlayerObject::setPosition(sf::Vector2f position)
{
	m_background.setPosition(position);
	calculateNewPos(position);
}
//--------------------------------------------
void BombChargePlayerObject::setSize()
{
	m_background.setSize(BACKGROUND_SIZE);
	m_bombCharge.setSize(BOMB_CHARGE_SIZE);
}
//--------------------------------------------
void BombChargePlayerObject::setColor()
{
	m_background.setFillColor(sf::Color::White);
	m_bombCharge.setFillColor(sf::Color(255, 200, 0));
}
//--------------------------------------------
void BombChargePlayerObject::setScale()
{
	m_background.setScale(BACKGROUND_SCALE[0],
		BACKGROUND_SCALE[1]);
	m_bombCharge.setScale(BOMB_RECTANGLE_SCALE[0],
		BOMB_RECTANGLE_SCALE[1]);
}
//--------------------------------------------
void BombChargePlayerObject::calculateNewPos(sf::Vector2f background)
{
	sf::Vector2f newPos(background.x + 2,
		background.y + RATIO_FOR_HEIGHT);
	m_bombCharge.setPosition(newPos);
}
//--------------------------------------------