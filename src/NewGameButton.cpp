#include "NewGameButton.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/Menu.h"
#include <iostream>

NewGameButton::NewGameButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

GameState* NewGameButton::onClick()
{
	std::cout << "New Game button clicked!" << std::endl;
	return new Menu();
}
