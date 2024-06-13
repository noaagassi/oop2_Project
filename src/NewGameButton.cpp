#include "NewGameButton.h"
#include "GameState.h"
#include <iostream>

NewGameButton::NewGameButton(const std::string& imagePath, float x, float y)
	:BaseButton(imagePath,x,y)
{
}

GameState* NewGameButton::onClick()
{
	std::cout << "New Game button clicked!" << std::endl;
	return GameState:: Play*;
}
