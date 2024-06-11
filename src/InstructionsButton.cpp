#include "InstructionsButton.h"
#include <iostream>

InstructionsButton::InstructionsButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

void InstructionsButton::onClick()
{
	std::cout << "instructions button pressed" << std::endl;
}
