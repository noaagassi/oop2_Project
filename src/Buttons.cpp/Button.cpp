#include "Buttons.h/Button.h"

Button::Button(std::unique_ptr<CommandButton> cmd, Object_ID name, float x, float y)
	: m_command(std::move(cmd))
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
	if (m_command) 
	{
		return m_command->execute();
	}
	else
	{
		throw std::runtime_error("Command is null");
	}
}

void Button::setScale(Object_ID name)
{
	sf::Vector2f currentSize(m_sprite.getTexture()->getSize());
	m_sprite.setScale(textureSize.x / currentSize.x, textureSize.y / currentSize.y);
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


