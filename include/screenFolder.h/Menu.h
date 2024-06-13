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
    void run();
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    GameState* changeState(sf::RenderWindow& window) override;

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    std::vector<BaseButton*> m_buttons;
    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;
};
