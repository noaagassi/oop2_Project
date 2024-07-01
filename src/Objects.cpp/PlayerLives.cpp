#include "Objects.h/PlayerLives.h"
PlayerLives::PlayerLives()
	:m_livesAmount(LIVEAMOUNT)
{
	setTextureAndSprite(HEARTS_PLAYER_OBJ);
}
//--------------------------------
PlayerLives::~PlayerLives()
{
}
//--------------------------------
void PlayerLives::setPosition(sf::Vector2f pos)
{
	m_livesSprite.setPosition(pos);
}
//--------------------------------
void PlayerLives::setTextureAndSprite(Object_ID name)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
	m_livesTexture = (*texturePtr);
	m_livesSprite.setTexture(*texturePtr);
	std::cout << "ok" << std::endl;
}
//--------------------------------



























/*
//--------------------------------
void PlayerLives::addLife()
{
	if (m_lifesCount < LIVEAMOUNT)
	{
		m_lifesCount++;
		update();
	}
}
//--------------------------------
bool PlayerLives::looseLife(int loose)
{
	for (int i = 0; i < loose; i++)
	{
		if (m_lifesCount - 1 > ENDLIVES)
		{
			m_lifesCount--;
			update();
		}
		else
		{
			return false;
		}
	}
	return true;
}
//--------------------------------
bool PlayerLives::stillLive()
{
	if (m_lifesCount > ENDLIVES)
	{
		return true;
	}
	return false;
}
//--------------------------------
void PlayerLives::updateSprite(sf::Vector2f position)
{
	m_lifesSprite.setPosition(position);
}
//--------------------------------
void PlayerLives::draw(sf::RenderWindow* window)
{
	window->draw(m_lifesSprite);
}
//--------------------------------
void PlayerLives::setTexture(Object_ID name)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
	m_lifesTexture = (*texturePtr);
	m_lifesSprite.setTexture(*texturePtr);
}
//--------------------------------
void PlayerLives::update()
{
	m_currFrame = LIVEAMOUNT - m_lifesCount;

	float scaleX = (float)(65) / m_frameWidth;
	float scaleY = (float)(20 * LIVEAMOUNT) / m_frameHeight;

	m_lifesSprite.setTextureRect(sf::IntRect(0, m_currFrame * m_frameHeight, m_frameWidth, m_frameHeight));
	m_lifesSprite.setScale(scaleX, scaleY);
}
//--------------------------------*/