#include "InstructionsButton.h"
#include <iostream>

InstructionsButton::InstructionsButton(const std::string& imagePath, float m_x, float m_y)
	:BaseButton(imagePath,m_x,m_y)
{
}

void InstructionsButton::onClick()
{
	std::cout << "instructions button pressed" << std::endl;
}
