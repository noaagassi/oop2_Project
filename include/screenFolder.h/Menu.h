#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "NewGameButton.h"
#include "ExitButton.h"
#include "InstructionsButton.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/Instructions.h"
#include "Utilities.h"

class Menu : public GameState
{
public:
    Menu(PlayState* play, Instructions* instructions);
    ~Menu();
    void run();
    void draw() override;
    void update() override;
    GameState* isStateChanged() override;
    
private:

    sf::RenderWindow m_window;
    std::vector<BaseButton*> m_buttons; // [exit, play, inst]
    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;

    

    std::unordered_map<StateOptions, GameState*> m_states;
};
