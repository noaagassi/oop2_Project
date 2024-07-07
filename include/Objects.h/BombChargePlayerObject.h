#pragma once
#include <SFML/Graphics.hpp>


const float LIMIT_SIZE = 46.0f;
const sf::Vector2f BACKGROUND_SIZE(50.0f, 20.0f);
const sf::Vector2f BOMB_CHARGE_SIZE(0.0f, 10.0f);
const float BACKGROUND_SCALE[2] = { 1.0f, 0.2f };
const float BOMB_RECTANGLE_SCALE[2] = { 1.0f, 0.2f };
const sf::Vector2f POS = { 60,50 };
const float RATIO_FOR_WIDTH = BACKGROUND_SIZE.x - 2,
RATIO_FOR_HEIGHT = ((BACKGROUND_SIZE.y - BOMB_CHARGE_SIZE.y) / 10);

class BombChargePlayerObject
{
public:
	BombChargePlayerObject(float,float);
	~BombChargePlayerObject() = default;
	void update(sf::Vector2f pos,float);
	void draw(sf::RenderWindow*) const;
	bool isCharge();
	void restartCharge();
private:
	void resizeBomb(float);
	void setRectangles();
	void setPosition(sf::Vector2f);
	void setSize();
	void setColor();
	void setScale();
	void calculateNewPos(sf::Vector2f);
	bool m_isCharge;
	sf::RectangleShape m_background;
	sf::RectangleShape m_bombCharge;
	sf::Clock m_clock;

};