#include "Buttons.h/ExitCommand.h"
#include <iostream>

StateOptions ExitCommand::execute()
{
	std::cout << "Exit button clicked!" << std::endl;
	return Exit;
}
