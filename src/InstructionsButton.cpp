#include "InstructionsButton.h"
#include <iostream>
#include "screenFolder.h/Menu.h"


InstructionsButton::InstructionsButton(const std::string& imagePath, float m_x, float m_y)
	:BaseButton(imagePath,m_x,m_y)
{
}

GameState* InstructionsButton::onClick()
{
	std::cout << "instructions button pressed" << std::endl;
	return new Menu();
}
