#include "Objects.h/PlayerLives.h"
//---------------------------------
PlayerLives::PlayerLives()
{

}
//---------------------------------
PlayerLives::PlayerLives(float x, float y)
{
	sf::Vector2f position(x, y);
	setRectangles(position);
}
//---------------------------------
void PlayerLives::draw(sf::RenderWindow* window) const
{
	window->draw(m_backproundRctangle);
	window->draw(m_lifesRectangle);
	//window->draw(m_heartSprite);
}
//---------------------------------
void PlayerLives::update(sf::Vector2f newPosition)
{
	setPosition(newPosition);
}
//---------------------------------
void PlayerLives::addLive()
{
	m_lifesRectangle.setSize({ m_lifesRectangle.getSize().x + 15, m_lifesRectangle.getSize().y });

	if (m_lifesRectangle.getSize().x > LIVES_RECTANGLE_SIZE.x)
	{
		m_lifesRectangle.setSize({ LIVES_RECTANGLE_SIZE.x, m_lifesRectangle.getSize().y });
	}
}
//---------------------------------
void PlayerLives::looseLive()
{
	if (m_lifesRectangle.getSize().x >= 3)
	{
		m_lifesRectangle.setSize({ m_lifesRectangle.getSize().x - 3, m_lifesRectangle.getSize().y });

	}
	else
	{
		sf::Vector2f currSize = m_lifesRectangle.getSize();
		currSize.x = 0;
		m_lifesRectangle.setSize(currSize);
	}
}
//---------------------------------
bool PlayerLives::stillAlive()
{
	if (m_lifesRectangle.getSize().x == 0)
	{
		return true;
	}
	return false;
}
//---------------------------------
void PlayerLives::setRectangles(sf::Vector2f position)
{
	setHeart(HEARTS_PLAYER_OBJ);
	setSize();
	setColor();
	setScale();
	setPosition(position);
}
//---------------------------------
void PlayerLives::setSize()
{
	m_backproundRctangle.setSize(BACKGROUND_RECTANGLE_SIZE);
	m_lifesRectangle.setSize(LIVES_RECTANGLE_SIZE);
}
//---------------------------------
void PlayerLives::setColor()
{
	m_backproundRctangle.setFillColor(sf::Color::White);
	m_lifesRectangle.setFillColor(sf::Color::Red);
}
//---------------------------------
void PlayerLives::setScale()
{
	m_backproundRctangle.setScale(BACKGROUND_RECTANGLE_SCALE[LIVES_WIDTH],
		BACKGROUND_RECTANGLE_SCALE[LIVE_HEIGHT]);
	m_lifesRectangle.setScale(LIVES_RECTANGLE_SCALE[LIVES_WIDTH],
		LIVES_RECTANGLE_SCALE[LIVE_HEIGHT]);
}
//---------------------------------
void PlayerLives::setPosition(sf::Vector2f position)
{
	m_backproundRctangle.setPosition(position);
	calculateNewPos(position);
	m_heartSprite.setPosition(position.x, position.y);
}
//---------------------------------

void PlayerLives::calculateNewPos(sf::Vector2f backgroundPosition)
{
	sf::Vector2f newPos(backgroundPosition.x + RATIO_4_WIDTH,
						backgroundPosition.y +RATIO_4_HEIGHT);
	//std::cout << "the Ratio is " << RATIO_4_HEIGHT << std::endl;
	m_lifesRectangle.setPosition(newPos);
}
//---------------------------------
void PlayerLives::setHeart(Object_ID name)
{
	sf::Texture texturePtr;
	texturePtr.loadFromFile("heartplayer.png");
	m_heartSprite.setTexture(texturePtr);
	sf::Vector2u theTextureSize = (texturePtr.getSize()) ;


	float scaleX = PLAY_WINDOW_WIDTH / (MAP_WIDTH * theTextureSize.x);
	float scaleY = PLAY_WINDOW_HEIGHT / (MAP_HEIGHT * theTextureSize.y);

	m_heartSprite.setScale(scaleX, scaleY);
}
//---------------------------------