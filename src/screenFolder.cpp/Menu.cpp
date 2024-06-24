//to do:
//handle the buttons exture



#include "Buttons.h/StartGameCommand.h"
#include "Buttons.h/InstructionsCommand.h"
#include "Buttons.h/ExitCommand.h"
#include "Buttons.h/Button.h"

#include "screenFolder.h/Menu.h"
#include <iostream>


Menu::Menu(sf::RenderWindow* window)
    : GameState(window) 
       
{
    setObjTexture(MENU_BACK_GROUND_OBJ);
    setScale(MENU_BACK_GROUND_OBJ);

    std::unique_ptr<CommandButton> startCmd = std::make_unique<StartGameCommand>();
    std::unique_ptr<CommandButton> instCmd = std::make_unique<InstructionsCommand>();
    std::unique_ptr<CommandButton> exitCmd = std::make_unique<ExitCommand>();


    m_buttons.push_back(std::make_unique<Button>(std::move(startCmd), NEW_GAME_BUTTON_OBJ, 100, 200));
    m_buttons.push_back(std::make_unique<Button>(std::move(instCmd), INSTRUCTION_BUTTON_OBJ, 100, 300));
    m_buttons.push_back(std::make_unique<Button>(std::move(exitCmd), EXIT_BUTTON_OBJ, 100, 400));
    
}

Menu::~Menu()
{
}


std::shared_ptr <GameState> Menu::isStateChanged()
{
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (auto& button : m_buttons) {
                    if (button->isMouseOver(m_window)) {
                        StateOptions state = button->click();
                        if (state == StateOptions::Exit)
                        {
                            m_window->close();
                        }
                        return m_states[state]; 
                    }
                }
            }
        }
    }
    return nullptr;
}





void Menu::update()
{
}

void Menu::draw()
{
    m_window->setTitle("Menu");
    m_window->clear();
    m_window->draw(m_backGroundSprite);

    for (auto& button : m_buttons) {
        button->draw(m_window);
    }
    m_window->display();
}
