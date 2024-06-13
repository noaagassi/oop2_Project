#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "NewGameButton.h"
#include "ExitButton.h"
#include "InstructionsButton.h"
#include "screenFolder.h/GameState.h"

class Menu : public GameState
{
public:
    Menu();
    //void run();
    void draw() override;
    void update() override;
    GameState* isStateChanged() override;

private:

    sf::RenderWindow m_window;
    std::vector<BaseButton*> m_buttons;
    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;
};
