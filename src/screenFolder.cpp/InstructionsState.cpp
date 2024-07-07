#pragma once

#include "screenFolder.h/InstructionsState.h"
#include "screenFolder.h/MenuState.h"
#include <iostream>
#include "Buttons.h/StartGameCommand.h"
#include "Buttons.h/NextCommand.h"
#include "Buttons.h/PreviousCommand.h"
#include "Buttons.h/MenuCommand.h"
#include "Buttons.h/Button.h"


Instructions:: Instructions(sf::RenderWindow* window)
    : GameState(window,1080,1000),
    m_currentPage(Page::Page1)
{
    setScale(INSTRUCTION_PAGE_1_OBJ);
    setObjTexture(INSTRUCTION_PAGE_1_OBJ);

    std::unique_ptr<CommandButton> nextCmd = std::make_unique<NextCommand>();
    std::unique_ptr<CommandButton> prevCmd = std::make_unique<PreviousCommand>();
    std::unique_ptr<CommandButton> menuCmd = std::make_unique<MenuCommand>();
    std::unique_ptr<CommandButton> playCmd = std::make_unique<StartGameCommand>();

    m_buttons.push_back(std::make_unique<Button>(std::move(nextCmd), NEXT_PAGE_BUTTON, 100, 200));
    m_buttons.push_back(std::make_unique<Button>(std::move(prevCmd), PREVIOUS_PAGE_BUTTON, 100, 300));
    m_buttons.push_back(std::make_unique<Button>(std::move(menuCmd), MENU_BUTTON, 100, 400));
    m_buttons.push_back(std::make_unique<Button>(std::move(playCmd), PLAY_BUTTON, 100, 400));

}

Instructions::~Instructions()
{
}


void Instructions::update(float deltatime)
{

}

void Instructions::handleEvent()
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {

        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (auto& button : m_buttons) {
                    if (button->isMouseOver(m_window)) {
                        StateOptions state = button->click();
                        if (state == StateOptions::Instruction1)
                        {
                            m_currentPage = Page::Page1;
                        }
                        else if (state == StateOptions::Instruction2)
                        {
                            m_currentPage = Page::Page2;
                        }
                    }
                }
            }
        }
    }
}

std::shared_ptr<GameState> Instructions::isStateChanged(sf::Event event)
{
    return std::shared_ptr<GameState>();
}



void Instructions::draw()
{
    if (m_currentPage == Page::Page1) 
    {
        setObjTexture(INSTRUCTION_PAGE_1_OBJ);
    }
    else if (m_currentPage == Page::Page2) 
    {
        setObjTexture(INSTRUCTION_PAGE_2_OBJ);
    }
    m_window->setTitle("Instructions");
    m_window->setSize(m_windowSize);
    m_window->clear();
    m_window->draw(m_backGroundSprite);
   // for (auto& button : m_buttons) {
     //   button->draw(m_window);
    //}
    m_window->display();
}
