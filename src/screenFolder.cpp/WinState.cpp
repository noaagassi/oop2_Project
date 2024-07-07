#include "screenFolder.h/WinState.h"
#include <iostream>
#include "SoundsHandler.h"

WinScreen::WinScreen(sf::RenderWindow* window)
    : GameState(window,800,600)
{
    setObjTexture(WIN_SCREEN_OBJ);
    setScale(WIN_SCREEN_OBJ);
}

WinScreen::~WinScreen()
{
}



void WinScreen::draw() 
{
    m_window->setTitle("WIN!");
    m_window->setSize(m_windowSize);
    m_window->clear();
    m_window->draw(m_backgroundSprite);
    SoundsHandler::getInstance().playSound(Sound_Id::WIN);
    //m_window->display();
}

void WinScreen::update(float deltatime) {
}

void WinScreen::handleEvent(sf::Event event)
{
}


std::shared_ptr <GameState> WinScreen::isStateChanged(sf::Event event) 
{
    if (event.type == sf::Event::Closed) {
        m_window->close();
    }
    return nullptr;
}
