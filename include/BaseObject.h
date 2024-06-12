#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class BaseObject {
public:
	BaseObject(const sf::Texture& texture, const sf::Vector2f& position) ;
	sf::Vector2f getSpriteLocation()const;
	void move(float offsetX, float offsetY);
	void draw(sf::RenderWindow& window) const;
	void setSpriteScale(float scaleX, float scaleY);
	const sf::Sprite& getSprite() const;

private:
	sf::Sprite m_objectSprite;
};