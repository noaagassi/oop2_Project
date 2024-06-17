#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(const std::string& imagePath, float x, float y)
	: BaseButton(imagePath, x, y)
{
}

StateOptions ExitButton::handleClick()
{
	std::cout << "Exit button clicked!" << std::endl;
	
	return StateOptions::Exit;
}
