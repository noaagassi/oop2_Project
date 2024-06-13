#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class BaseButton {
public:
    BaseButton(const std::string& imagePath, float x, float y);
    virtual ~BaseButton() = default;

    virtual void onClick() = 0;
    void render(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
