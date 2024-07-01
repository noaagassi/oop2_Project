#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "TextureHandler.h"
#include <iostream>

const int LIVES_WIDTH = 0;
const int LIVE_HEIGHT = 1;
const sf::Vector2f BACKGROUND_RECTANGLE_SIZE(65.0f, 40.0f);
const sf::Vector2f LIVES_RECTANGLE_SIZE(60.0f, 20.0f);
const float BACKGROUND_RECTANGLE_SCALE[2] = { 1.0f, 0.2f };
const float LIVES_RECTANGLE_SCALE[2] = { 1.0f, 0.2f };
const float RATIO_4_WIDTH = (BACKGROUND_RECTANGLE_SIZE.x - LIVES_RECTANGLE_SIZE.x) / 2,
RATIO_4_HEIGHT = (BACKGROUND_RECTANGLE_SIZE.y - LIVES_RECTANGLE_SIZE.y) / 2;

class PlayerLives
{
public:
	PlayerLives();
	PlayerLives(float,float);
	void draw(sf::RenderWindow*) const;
	void update(sf::Vector2f);

	void looseLive();
	bool stillAlive();
private:
	sf::Sprite m_heartSprite;
	sf::RectangleShape m_backproundRctangle;
	sf::RectangleShape m_lifesRectangle;

	//function for rectangles
	void setRectangles(sf::Vector2f);
	void setSize();
	void setColor();
	void setScale();
	void setPosition(sf::Vector2f);
	void calculateNewPos(sf::Vector2f);
	
	//function for the picure
	void setHeart(Object_ID);
};	