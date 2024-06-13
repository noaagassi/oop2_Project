#include "NewGameButton.h"
#include <iostream>

NewGameButton::NewGameButton(const std::string& imagePath, float m_x, float m_y)
	:BaseButton(imagePath,m_x,m_y)
{
}

void NewGameButton::onClick()
{
	std::cout << "New Game button clicked!" << std::endl;
}
