#include "Controller.h"

Controller::Controller()
	: m_window(sf::VideoMode(PLAY_WINDOW_HEIGHT, PLAY_WINDOW_WIDTH), "Brawl Stars",
	sf::Style::Close | sf::Style::Titlebar),
	m_menu(std::make_shared<Menu>(&m_window)),
	m_playState(std::make_shared<PlayState>(&m_window)),
	m_instructions(std::make_shared<Instructions>(&m_window)),
    m_pause(std::make_shared<PausePage>(&m_window))
{
	m_menu->initMap(m_playState, StateOptions::PlayScrn);
	m_menu->initMap(m_instructions, StateOptions::InstructionsScrn);

    m_playState->initMap(m_pause, StateOptions::PauseScrn);

    m_pause->initMap(m_playState, StateOptions::PlayScrn);
    m_pause->initMap(m_instructions, StateOptions::InstructionsScrn);
    m_pause->initMap(m_menu, StateOptions::MenuScrn);

//    m_loose->initMap(m_menu, StateOptions::MenuScrn);

	m_currentScreen = m_menu;

    SoundsHandler::getInstance().playMusic();
}





void Controller::run() {
    sf::Clock clock;
    sf::View originView = m_window.getDefaultView();

    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        m_currentScreen->draw();
        m_currentScreen->update(deltaTime);
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

            
            std::shared_ptr<GameState> nextScreen = m_currentScreen->isStateChanged(event);
            bool screenChanged = (nextScreen != nullptr);
            if (screenChanged)
            {
                m_currentScreen = nextScreen;
            }
            if (dynamic_cast<PlayState*>(m_currentScreen.get()) == nullptr)
            {
                m_window.setView(originView);
            }
            
        }
        

            m_currentScreen->update(deltaTime);

            
            //m_window.clear();
            m_currentScreen->draw();
            m_window.display();
        

    }
}

