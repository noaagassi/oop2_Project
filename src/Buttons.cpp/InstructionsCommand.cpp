#include "Buttons.h/InstructionsCommand.h"
#include <iostream>

StateOptions InstructionsCommand::execute()
{
	std::cout << "instructions button clicked!" << std::endl;
	return InstructionsScrn;
}
