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

    StartGameCommand startCmd;
    InstructionsCommand instCmd;
    ExitCommand exitCmd;

    /* new?
    m_startButton= Button(&startCmd, NEW_GAME_BUTTON_OBJ, 100, 200);
    m_instructionsButton= Button(&instCmd,INSTRUCTION_BUTTON_OBJ, 100, 300);
    m_exitButton= Button(&exitCmd, EXIT_BUTTON_OBJ, 100, 400);
    */

    m_buttons.push_back(new Button(&startCmd, NEW_GAME_BUTTON_OBJ, 100, 200));
    m_buttons.push_back(new Button(&instCmd, INSTRUCTION_BUTTON_OBJ, 100, 300));
    m_buttons.push_back(new Button(&exitCmd, EXIT_BUTTON_OBJ, 100, 400));
    
    /* old
    m_buttons.push_back(new NewGameButton("new_game.png", 100, 200));
    m_buttons.push_back(new ExitButton("exit_button.png", 100, 300));
    m_buttons.push_back(new InstructionsButton("instructions.png", 100, 400));
    */
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
