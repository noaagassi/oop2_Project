#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "NewGameButton.h"
#include "ExitButton.h"
#include "InstructionsButton.h"

class Menu
{
public:
    Menu();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    std::vector<BaseButton*> m_buttons;
    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;
};
