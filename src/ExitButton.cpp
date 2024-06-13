#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(const std::string& imagePath, float m_x, float m_y)
	: BaseButton(imagePath, m_x, m_y)
{
}

GameState* ExitButton::onClick()
{
	std::cout << "Exit button clicked!" << std::endl;
	
	return nullptr;
}
