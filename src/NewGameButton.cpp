#include "NewGameButton.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/Menu.h"
#include <iostream>

NewGameButton::NewGameButton(const std::string& imagePath, float m_x, float m_y)
	:BaseButton(imagePath,m_x,m_y)
{
}

GameState* NewGameButton::onClick()
{
	std::cout << "New Game button clicked!" << std::endl;
	return new Menu();
}
