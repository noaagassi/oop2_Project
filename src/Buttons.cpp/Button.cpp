#include "Buttons.h/Button.h"

Button::Button(CommandButton* cmd, Object_ID name, float x, float y)
	: m_command(cmd) 
{	

	setTexture(name);
	setScale(name);
	m_sprite.setPosition(x, y);
}

Button::Button()
{
}

StateOptions Button::click()
{
	return m_command->execute();
}

void Button::setScale(Object_ID name)
{
}

void Button::setTexture(Object_ID name)
{
	sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
	m_sprite.setTexture(*texturePtr);
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}

bool Button::isMouseOver(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	return m_sprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

}


