#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "TextureHandler.h"

const int LIVEAMOUNT = 6;
const int ENDLIVES = 0;
const int FRAMEWIDTH = 65;
const int FRAMEHEIGHT = 20;

class PlayerLives
{
public:
	PlayerLives();
	~PlayerLives();

	void setPosition(sf::Vector2f);
	void update();
	void draw(sf::RenderWindow*) const;
private:
	int m_livesAMount;
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_currentFrame;

	void setScale();
	void setTexture(Object_ID);
};



/*
	void addLife();
	bool looseLife(int);
	bool stillLive();
	void updateSprite(sf::Vector2f);
	void draw(sf::RenderWindow* window);
private:
	int m_lifesCount;
	sf::Sprite m_lifesSprite;
	sf::Texture m_lifesTexture;
	int m_frameWidth;
	int m_frameHeight;
	int m_currFrame;
	void setTexture(Object_ID);
	void update();*/
	