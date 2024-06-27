#include "Controller.h"
#include "screenFolder.h/Menu.h"

Controller::Controller()
	:m_view(sf::FloatRect(0,0,400,300)),
    m_window(sf::VideoMode(800, 600), "Brawl Stars",
	sf::Style::Close | sf::Style::Titlebar),
	m_menu(std::make_shared<Menu>(&m_window)),
	m_playState(std::make_shared<PlayState>(&m_window)),
	m_instructions(std::make_shared<Instructions>(&m_window))
{
	m_menu->initMap(m_playState, StateOptions::PlayScrn);
	m_menu->initMap(m_instructions, StateOptions::InstructionsScrn);
	m_playState->initMap(m_menu, StateOptions::MenuScrn);


	m_currentScreen = m_menu;
}





void Controller::run() {
    sf::Clock clock;
        
    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        m_currentScreen->draw();
        //m_currentScreen->update(deltaTime);////////////////////////////////////////////////
        // ניהול אירועים
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            // בדיקה אם יש שינוי מצב
            std::shared_ptr<GameState> nextScreen = m_currentScreen->isStateChanged(event);
            bool screenChanged = (nextScreen != nullptr);
            if (screenChanged) {
                m_currentScreen = nextScreen;
            }

            //// העברת האירועים למצב הנוכחי רק אם המסך לא השתנה
            //if (!screenChanged) {
            //    m_currentScreen->handleEvent();
            //}
            //// עדכון מצב נוכחי
            m_currentScreen->update(deltaTime);
/*
            if (std::dynamic_pointer_cast<PlayState>(m_currentScreen)) {

                m_view.setCenter(m_currentScreen.getPlayerLoction());
            }*/
            if (auto playState = std::dynamic_pointer_cast<PlayState>(m_currentScreen))
            {
                handleView(playState);
            }

            // ציור מצב נוכחי
            m_window.clear();
            m_currentScreen->draw();
            m_window.display();
        }

    }
}



void Controller::handleView(std::shared_ptr<PlayState> playState)
{
    m_view.setCenter(playState->getPlayerLocation());
    m_view.setSize(VIEW_WIDTH, VIEW_HEIGHT);
    m_window.setView(m_view);


    sf::FloatRect playerBounds = m_playState->getPlayerBounds();
    sf::FloatRect mapBounds;    
    mapBounds.left = 0.0f;      
    mapBounds.top = 0.0f;      
    mapBounds.width = MAP_WIDTH; 
    mapBounds.height = MAP_HEIGHT;

    bool nearTop = playerBounds.top < mapBounds.top + mapBounds.height / 2;
    bool nearBottom = playerBounds.top + playerBounds.height > mapBounds.top + mapBounds.height / 2;
    bool nearLeft = playerBounds.left < mapBounds.left + mapBounds.width / 2;
    bool nearRight = playerBounds.left + playerBounds.width > mapBounds.left + mapBounds.width / 2;
}
