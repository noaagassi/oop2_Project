#include "Objects.h/PlayerLives.h"
PlayerLives::PlayerLives()
	:m_livesAMount(LIVEAMOUNT)
{
	setTexture(HEARTS_PLAYER_OBJ);
	setScale();
}
//--------------------------------
void PlayerLives::setPosition(sf::Vector2f pos)
{
	m_position.x = pos.x;
	m_position.y = pos.y;
	m_sprite.setPosition(m_position);
}
//--------------------------------
void PlayerLives::update()
{
	m_currentFrame = LIVEAMOUNT - m_livesAMount;
	m_sprite.setTextureRect(sf::IntRect(0, m_currentFrame * (m_texture.getSize().y / LIVEAMOUNT),
		m_texture.getSize().x, m_texture.getSize().y / LIVEAMOUNT));
}
//--------------------------------
void PlayerLives::draw(sf::RenderWindow* window) const
{
	window->draw(m_sprite);
}
//--------------------------------
void PlayerLives::setScale()
{
	float x = (float)(FRAMEWIDTH / m_texture.getSize().x);
	float y = (float)(FRAMEHEIGHT / m_texture.getSize().y);

	m_sprite.setScale(x, y);

	update();
	
}
//--------------------------------
void PlayerLives::setTexture(Object_ID name)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
	m_texture = (*texturePtr);
	m_sprite.setTexture(*texturePtr);
}
//--------------------------------
PlayerLives::~PlayerLives()
{
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