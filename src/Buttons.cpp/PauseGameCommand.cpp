#include "Buttons.h/PauseGameCommand.h"
#include <iostream>

StateOptions PauseGameCommand::execute()
{
	std::cout << "Pause button clicked!" << std::endl;
	return PauseScrn;
}
 