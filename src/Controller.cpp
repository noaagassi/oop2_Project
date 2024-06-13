
#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(800,600), "Brawl Stars",
		sf::Style::Close | sf::Style::Titlebar)
{
	m_currentScreen = GameState::Menu*;
}

void Controller::run() {

	while (m_window.isOpen())
	{
		m_window.events();
		m_window.display();
		m_window.clear();

		GameState* nextScreen = m_currentScreen->isStateChanged(m_window);
		if (nextScreen)
		{
			m_currentScreen = nextScreen;
		}
		m_currentScreen->update();
		m_currentScreen->draw();
	}
}

