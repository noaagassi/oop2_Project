#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class BaseButton {
public:
    BaseButton(const std::string& imagePath, float m_x, float m_y);
    virtual ~BaseButton() = default;

    virtual void onClick() = 0;
    void render(sf::RenderWindow& m_window);
    bool isMouseOver(sf::RenderWindow& m_window);

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
