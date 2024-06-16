#include "BaseButton.h"

BaseButton::BaseButton(const std::string& imagePath, float x, float y)
{
    if (!m_texture.loadFromFile(imagePath)) {
        // error
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);

    sf::Vector2f currentSize(m_sprite.getTexture()->getSize());
    m_sprite.setScale(textureSize.x / currentSize.x, textureSize.y / currentSize.y);
}

void BaseButton::render(sf::RenderWindow& m_window)
{
    m_window.draw(m_sprite);
}

bool BaseButton::isMouseOver(sf::RenderWindow& m_window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    return m_sprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
   
}
