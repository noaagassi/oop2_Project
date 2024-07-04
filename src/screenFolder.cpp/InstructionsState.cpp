//to do:
//need to handle 2 nd page of instructon
//need to check the button texture here



#pragma once

#include "screenFolder.h/InstructionsState.h"
#include "screenFolder.h/MenuState.h"
#include <iostream>

Instructions:: Instructions(sf::RenderWindow* window)
    : GameState(window,1000,500),
    m_currentPage(Page::Page1)
{
    setScale(INSTRUCTION_PAGE_1_OBJ);
    setObjTexture(INSTRUCTION_PAGE_1_OBJ);
}

Instructions::~Instructions()
{
}


void Instructions::update(float deltatime)
{
}

void Instructions::handleEvent(sf::Event event)
{
}
/*
std::shared_ptr<GameState> Instructions::isStateChanged(sf::Event event)
{
    return std::shared_ptr<GameState>();
}
*/


void Instructions::draw()
{
    m_window->setTitle("Instructions");
    m_window->setSize(m_windowSize);
    

    if (m_currentPage == Page::Page1) {
    }
    else if (m_currentPage == Page::Page2) {
    }
}
