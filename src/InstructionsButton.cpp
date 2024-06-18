#include "InstructionsButton.h"
#include <iostream>
#include "screenFolder.h/Menu.h"


InstructionsButton::InstructionsButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

StateOptions InstructionsButton::handleClick()
{
	std::cout << "instructions button pressed" << std::endl;
	return StateOptions::InstructionsScrn;
}
