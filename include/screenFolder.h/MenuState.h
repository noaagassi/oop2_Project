//to do:
//check if vector buttons needed




#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/InstructionsState.h"
#include "Buttons.h/Button.h"
#include "Utilities.h"

class Menu : public GameState
{
public:
    Menu(sf::RenderWindow* window);
    ~Menu();
    void draw() override;
    void update(float deltatime) override;
    void handleEvent(sf::Event event);
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;
   
    
private:

    std::vector<std::unique_ptr<Button>> m_buttons; // [exit, play, inst]
   
};
