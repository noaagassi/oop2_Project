#pragma once
#include "Buttons.h/CommandButton.h"
#include "Utilities.h"
#include "TextureHandler.h"
#include <string>

class Button {

public:
    Button(CommandButton* cmd, Object_ID name, float x, float y);
    Button();
     

    StateOptions click();

    void setScale(Object_ID name);
    void setTexture(Object_ID name);

    void draw(sf::RenderWindow* window);
    bool isMouseOver(sf::RenderWindow* window);

private:
    CommandButton* m_command;
    sf::Sprite m_sprite;
};