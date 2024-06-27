
#include "Buttons.h/StartGameCommand.h"
#include "Buttons.h/InstructionsCommand.h"
#include "Buttons.h/ExitCommand.h"
#include "Buttons.h/ResumeGameCommand.h"
#include "Buttons.h/Button.h"

#include "screenFolder.h/PausePage.h"
#include <iostream>


PausePage::PausePage(sf::RenderWindow* window)
    : GameState(window,800,600)

{

    setScale(PAUSE_SCREEN_OBJ);
    setObjTexture(PAUSE_SCREEN_OBJ);

    std::unique_ptr<CommandButton> startCmd = std::make_unique<StartGameCommand>();
    std::unique_ptr<CommandButton> instCmd = std::make_unique<InstructionsCommand>();
    std::unique_ptr<CommandButton> exitCmd = std::make_unique<ExitCommand>();
    std::unique_ptr<CommandButton> resumeCmd = std::make_unique<ResumeGameCommand>();

    m_buttons.push_back(std::make_unique<Button>(std::move(startCmd), NEW_GAME_BUTTON_OBJ, 300, 100));
    m_buttons.push_back(std::make_unique<Button>(std::move(instCmd), INSTRUCTION_BUTTON_OBJ, 300, 200));
    m_buttons.push_back(std::make_unique<Button>(std::move(exitCmd), EXIT_BUTTON_OBJ, 300, 300));
    m_buttons.push_back(std::make_unique<Button>(std::move(resumeCmd), RESUME_GAME_BUTTON_OBJ, 300, 100));

}

PausePage::~PausePage()
{
}

void PausePage::draw()
{
    // to do on top of the window, and save the game that was runing
    m_window->setTitle("Pause");
    m_window->setSize(m_windowSize);
    m_window->clear();
    m_window->draw(m_backGroundSprite);

    for (auto& button : m_buttons) {
        button->draw(m_window);
    }
    m_window->display();
}

void PausePage::update(float deltatime)
{
}

void PausePage::handleEvent(sf::Event event)
{

}

std::shared_ptr<GameState> PausePage::isStateChanged(sf:: Event event)
{
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

    return nullptr;
}
