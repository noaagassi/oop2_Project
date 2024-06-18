#include "BaseButton.h"

BaseButton::BaseButton(const std::string& imagePath, float x, float y)
{
    if (!m_texture.loadFromFile(imagePath)) {
        // error
    }
    m_buttonSprite.setTexture(m_texture);
    m_buttonSprite.setPosition(x, y);

    sf::Vector2f currentSize(m_buttonSprite.getTexture()->getSize());
    m_buttonSprite.setScale(textureSize.x / currentSize.x, textureSize.y / currentSize.y);
}


void BaseButton::setObjTexture(int objNum)
{
    sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(objNum);
    m_buttonSprite.setTexture(*texturePtr);
}


void BaseButton::render(sf::RenderWindow* m_window)
{
    m_window->draw(m_buttonSprite);
}

bool BaseButton::isMouseOver(sf::RenderWindow* m_window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
    return m_buttonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
   
}
