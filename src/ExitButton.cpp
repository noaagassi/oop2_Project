#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(const std::string& imagePath, float x, float y)
	: BaseButton(imagePath, x, y)
{
}

GameState* ExitButton::onClick()
{
	std::cout << "Exit button clicked!" << std::endl;
	
	return nullptr;
}
