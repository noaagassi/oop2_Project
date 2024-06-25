#include "screenFolder.h/LooseScreen.h"
#include <iostream>


LooseScreen::LooseScreen(sf::RenderWindow* window)
    : GameState(window)

{
    
    setObjTexture(LOOSE_SCREEN_OBJ);
    setScale(LOOSE_SCREEN_OBJ);


    /*m_buttons.push_back(new NewGameButton("new_game.png", 100, 200));
    m_buttons.push_back(new ExitButton("exit.png", 100, 300));
    m_buttons.push_back(new InstructionsButton("instructions.png", 100, 400));*/
}

LooseScreen::~LooseScreen()
{
}

void LooseScreen::draw()
{
}

void LooseScreen::update()
{
}

std::shared_ptr<GameState> LooseScreen::isStateChanged(sf::Event event)
{
    return std::shared_ptr<GameState>();
}
