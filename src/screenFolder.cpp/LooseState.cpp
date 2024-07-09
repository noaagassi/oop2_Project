#include "screenFolder.h/LooseState.h"

#include "Buttons.h/MenuCommand.h"
#include <iostream>


LooseScreen::LooseScreen(sf::RenderWindow* window)
    : GameState(window,1080,1000)

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
    m_window->setTitle("GAME OVER");
    m_window->setSize(m_windowSize);
    m_window->clear();
    m_window->draw(m_backGroundSprite);

 //   m_window->display();
}

void LooseScreen::update(float deltatime)
{
}
void LooseScreen::handleEvent(sf::Event event)
{
}

std::shared_ptr<GameState> LooseScreen::isStateChanged(sf::Event event)
{

    return nullptr;
}
