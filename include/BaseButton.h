#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include "screenFolder.h/GameState.h"

class BaseButton {
public:
    BaseButton(const std::string& imagePath, float x, float y);
    virtual ~BaseButton() = default;
    
    void setObjTexture(Object_ID name);
    void setScale();


    virtual StateOptions handleClick() = 0;
    void render(sf::RenderWindow* window);
    bool isMouseOver(sf::RenderWindow* window);

protected:
    sf::Texture m_texture;
    sf::Sprite m_buttonSprite;
};
