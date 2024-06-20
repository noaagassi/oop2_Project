//to do:
//check if vector buttons needed




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
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged() override;
   
    
private:

   
    std::vector<BaseButton*> m_buttons; // [exit, play, inst]
   
};
