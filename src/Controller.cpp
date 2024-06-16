#include "Controller.h"
#include "screenFolder.h/Menu.h"

Controller::Controller()
	:m_window(sf::VideoMode(800, 600), "Brawl Stars",
	sf::Style::Close | sf::Style::Titlebar),
	m_menu(std::make_shared<Menu>()),
	m_playState(std::make_shared<PlayState>()),
	m_instructions(std::make_shared<Instructions>())
{
	m_menu->initMap(m_playState, StateOptions::PlayScrn);
	m_menu->initMap(m_instructions, StateOptions::InstructionsScrn);

	m_playState->initMap(m_menu, StateOptions::MenuScrn);



	m_currentScreen = m_menu;
}

void Controller::run() {
	sf::Clock clock;

	while (m_window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		//m_window.events();
		m_window.display();
		m_window.clear();

		std::shared_ptr <GameState> nextScreen = m_currentScreen->isStateChanged();
		if (nextScreen)
		{
			m_currentScreen = nextScreen;
		}
		m_currentScreen->update();
		m_currentScreen->draw();
	}
}

void Controller::update(float deltaTime)
{
	m_playerObject.update(deltaTime);
}

void Controller::render() {
	m_window.clear();
	m_playerObject.draw(m_window);
	m_window.display();
}