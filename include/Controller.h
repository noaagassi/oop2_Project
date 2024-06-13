#pragma once
#include <SFML/Graphics.hpp>
#include "screenFolder.h/GameState.h"

class Controller {
public:
	Controller();
	void run();
private:
	sf::RenderWindow m_window;
	GameState* m_currentScreen;
};

