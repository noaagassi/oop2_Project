#pragma once
#include "InstructionsButton.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/Instructions.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>



class LooseScreen : public GameState
{
public:
    LooseScreen(sf::RenderWindow* window);
    ~LooseScreen();
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged() override;

private:


    std::vector<BaseButton*> m_buttons; // []




  
};
