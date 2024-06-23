#include "screenFolder.h/PausePage.h"
#include <iostream>


PausePage::PausePage(sf::RenderWindow* window)
    : GameState(window)

{

    setObjTexture(PAUSE_SCREEN_OBJ);
    setScale(PAUSE_SCREEN_OBJ);


    /*m_buttons.push_back(new NewGameButton("new_game.png", 100, 200));
    m_buttons.push_back(new ExitButton("exit.png", 100, 300));
    m_buttons.push_back(new InstructionsButton("instructions.png", 100, 400));*/
}

PausePage::~PausePage()
{
}

void PausePage::draw()
{
}

void PausePage::update()
{
}

std::shared_ptr<GameState> PausePage::isStateChanged()
{
    return std::shared_ptr<GameState>();
}
