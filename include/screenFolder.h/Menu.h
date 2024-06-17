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
    Menu(sf::RenderWindow* window);
    ~Menu();
    void run();
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged() override;
    //void initMap(GameState* state_ptr, StateOptions state_name);
    
private:

   
    std::vector<BaseButton*> m_buttons; // [exit, play, inst]
    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;

    

    //std::unordered_map<StateOptions, GameState*> m_states;
};
