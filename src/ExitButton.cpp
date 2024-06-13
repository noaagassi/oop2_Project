#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(const std::string& imagePath, float x, float y)
	: BaseButton(imagePath, x, y)
{
}

void ExitButton::onClick()
{
	std::cout << "Exit button clicked!" << std::endl;
}
