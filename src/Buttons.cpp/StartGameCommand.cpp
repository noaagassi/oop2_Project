#include "Buttons.h/StartGameCommand.h"
#include <iostream>

StateOptions StartGameCommand::execute()
{
	std::cout << "New Game button clicked!" << std::endl;
	return PlayScrn;
}
