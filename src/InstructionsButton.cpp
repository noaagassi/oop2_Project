#include "InstructionsButton.h"
#include <iostream>
#include "screenFolder.h/Menu.h"


InstructionsButton::InstructionsButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

GameState* InstructionsButton::onClick()
{
	std::cout << "instructions button pressed" << std::endl;
	return new Menu();
}
