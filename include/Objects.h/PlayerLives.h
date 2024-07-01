#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "TextureHandler.h"
#include <iostream>

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
private:
	int m_livesAmount;
	sf::Texture m_livesTexture;
	sf::Sprite m_livesSprite;

	//set function
	void setTextureAndSprite(Object_ID);
};	