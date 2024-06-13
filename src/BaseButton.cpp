#include "BaseButton.h"

BaseButton::BaseButton(const std::string& imagePath, float m_x, float m_y)
{
    if (!m_texture.loadFromFile(imagePath)) {
        // error
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_x, m_y);

    sf::Vector2f currentSize(m_sprite.getTexture()->getSize());
//    m_sprite.setScale(textureSize.m_x / currentSize.m_x, textureSize.m_y / currentSize.m_y);
}

void BaseButton::render(sf::RenderWindow& m_window)
{
    m_window.draw(m_sprite);
}

bool BaseButton::isMouseOver(sf::RenderWindow& m_window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    //return m_sprite.getGlobalBounds().contains(static_cast<float>(mousePos.m_x), static_cast<float>(mousePos.m_y));
    return false;
}
