#include "screenFolder.h/WinScreen.h"
#include <iostream>

WinScreen::WinScreen(sf::RenderWindow* window)
    : GameState(window)
{
    setObjTexture(WEEN_SCREEN_OBJ);
    setScale(WEEN_SCREEN_OBJ);
}

WinScreen::~WinScreen()
{
}



void WinScreen::draw() {
    /*m_window.clear();
    m_window.draw(m_backgroundSprite);
    m_window.draw(m_menuButtonSprite);
    m_window.draw(m_exitButtonSprite);
    m_window.display();*/
}

void WinScreen::update() {
}

//
//std::shared_ptr <GameState> WinScreen::isStateChanged() {
//    return nullptr;         /////to change!!!!!
//}

std::shared_ptr <GameState> WinScreen::isStateChanged(sf::Event event) {
    return nullptr;         /////to change!!!!!
}
