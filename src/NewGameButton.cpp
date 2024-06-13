#include "NewGameButton.h"
#include <iostream>

NewGameButton::NewGameButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

void NewGameButton::onClick()
{
	std::cout << "New Game button clicked!" << std::endl;
}
